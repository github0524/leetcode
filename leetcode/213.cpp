#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subrob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            if (i == 2) dp[2] = nums[1];
            if (i >= 3)
            {
                dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i - 1];
            }
        }
        return max(dp[n], dp[n - 1]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return  max(nums[0],nums[1]);
        //>2 
        vector<int> nums1(nums.begin(), nums.end() -1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        //如果不包含0，那么可以遍历到最后
        //如果包含0，那么可以包含到倒数第二个
        return max(subrob(nums1), subrob(nums2));
    }
};

int main()
{
    Solution so;
    vector<int> nums{ 1,2,3,1 };
    cout << so.rob(nums) << endl;
    return 0;
}