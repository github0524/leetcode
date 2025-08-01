#include <vector>
#include <iostream>

using namespace std;

//子数组是连续的
class Solution {
public:
    int findLength(vector<int> nums1, vector<int> nums2) {
        //dp 以i-1结尾的A ，和以j-1结尾的B
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));
        int max_length = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max_length = max(max_length, dp[i][j]);
                }
            }

        }
        return max_length;
    }
};

int main()
{
    Solution so;
    cout << so.findLength({} ,{}) << endl;
}