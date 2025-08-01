#include <vector>
#include <iostream>


using namespace std;
//最长严格递增子序列 相等的不算
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //01背包问题
        int n = nums.size();
        vector<int> dp(n+1,INT_MAX);
        //dp代表长度能够达到i的最小值是谁
        dp[0] = INT_MIN;
        dp[1] = nums[0];
        int len = 1;
        //数字
        for (int i = 1; i < n; i++)
        {
            //长度
            for (int j = 1; j <= i+1; j++)
            {
                if (nums[i]<dp[j]&&nums[i]>dp[j-1])
                {
                    dp[j] = nums[i];
                    len = max(len, j);
                }
            }
        }
        return len;
    }
};