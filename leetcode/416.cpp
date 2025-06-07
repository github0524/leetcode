
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 2 3 3  4 5
// 左右相等 、 只有两部分  、 加法
//首先 不能有一个数超过一半的和
// 和是奇数的肯定不行
//也就是算 最大的数字+某个数字能不能到总数的一半（这个数字一定小于半数-最大的数）

//总结就是0/1背包问题里面有没有组合能让总的value能够达到 sum/2
//为什么每一步都要求步骤的最大值？因为01背包问题本就是指的，一定重量下面能有一个组合出的价值最大
//本题的重量和价值相等了，对于符合题目条件的组合，一定是存在这样的组合的，反之就不存在


//看视频
//每一列的物品不是按照顺序拍的，完全离散，只考虑放入和不放入的情况是否能对应到每一行上面的值，只有true和false

//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        int sum = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            sum += nums[i];
//        }
//        //奇数
//        if (sum%2==1)
//        {
//            return false;
//        }
//        vector<vector<bool>> dp(nums.size(), vector<bool>(sum/2 + 1, false));
//        if (nums[0]<= sum/2)
//        {
//            dp[0][nums[0]] = true;
//        }
//        for (int i = 1; i < nums.size(); i++)
//        {
//            //不能有一个数大于一半
//            if (nums[i]>sum/2)
//            {
//                return false;
//            }
//            for (int j = 0; j < nums[i]; j++) {
//                dp[i][j] == dp[i - 1][j];
//            }
//            //不会出现j<nums[i]
//            for (int j = nums[i]; j <=sum/2; j++)
//            {
//                //不选
//                if (dp[i-1][j]==true)
//                {
//                    dp[i][j] = true;
//                    continue;
//                }
//                //选
//                if (nums[i]==sum/2)
//                {
//                    return true;
//                }
//                dp[i][j] = dp[i - 1][j - nums[i]];
//            }
//        }
//        return dp[nums.size() - 1][sum / 2];
//    }
//};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        if (n < 2)
            return false;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        int max = *max_element(nums.begin(), nums.end());
        int target = sum / 2;
        if (max>target)
            return false;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

//dp打印
/*for (int i = 0; i < dp[0].size(); i++)
{
    cout << "\t" << i;
}
cout << endl;
for (int i = 0; i < dp.size(); i++)
{
    cout << nums[i] << "\t";

    for (int j = 0; j < dp[0].size(); j++)
        cout << dp[i][j] << "\t";
    cout << endl;
}*/
//使用 accumulate 和 max_element，代码更简洁，易于理解。
//提前检查 maxNum > target，逻辑更清晰，可能在实际运行中更快。
//明确处理 $n < 2$ 的边界情况，符合编程规范。
//官方写的更好，且对于选与不选的归纳更清晰
//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        int n = nums.size();
//        if (n < 2) {
//            return false;
//        }
//        int sum = accumulate(nums.begin(), nums.end(), 0);
//        int maxNum = *max_element(nums.begin(), nums.end());
//        if (sum & 1) {
//            return false;
//        }
//        int target = sum / 2;
//        if (maxNum > target) {
//            return false;
//        }
//        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
//        for (int i = 0; i < n; i++) {
//            dp[i][0] = true;
//        }
//        dp[0][nums[0]] = true;
//        for (int i = 1; i < n; i++) {
//            int num = nums[i];
//            for (int j = 1; j <= target; j++) {
//                if (j >= num) {
//                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
//                }
//                else {
//                    dp[i][j] = dp[i - 1][j];
//                }
//            }
//        }
//        return dp[n - 1][target];
//    }
//};

int main()
{
    Solution so;
    vector<int> nums{ 1,5,11,5 };
    cout << so.canPartition(nums) << endl;
    return 0;

}