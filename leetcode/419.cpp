#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //两部分 A-B = S
        //A+B = sum ,2A=S+sum A=(S+sum)/2
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        //根据前面的关系，A是一个整数，所以S+sum一定是一个偶数，否则直接返回0 或者target的绝对值是一个sum无法达到的值直接返回
        if ((target + sum) % 2 == 1 || sum < abs(target)) return 0;
        int new_target =abs(( target + sum )/ 2);
        vector<int> dp(new_target + 1, 0);
        //从前i个数的集合中找出和为new_target的组合有多少，就是需要把前面已经出现的组合数量+加入当前元素的可能组合数量
        dp[0] = 1; //转化为1维，代表和为0的可能性有一种，就是不选
        for (int i = 0; i < nums.size(); i++)
        {

            for (int j= new_target;j>=nums[i];j--)
            {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[new_target];

    }
};

int main()
{
    Solution so;
    vector<int> nums{ 100 };
    cout << so.findTargetSumWays(nums, -50) << endl;
}