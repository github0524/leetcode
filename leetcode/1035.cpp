#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //最长公共子序列绝对不会相交
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                
            }

        }
        return dp[m][n];
    }
};

int main()
{
    vector<int> nums1{ 1,4,2 };
    vector<int> nums2{ 1,2,4 };
    Solution so;
    cout << so.maxUncrossedLines(nums1, nums2) << endl;
}