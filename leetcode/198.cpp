#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            if (i == 2) dp[2] = nums[1];
            if (i>=3)
            {
                dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i - 1];
            }
        }
        return max(dp[n], dp[n - 1]);
    }
};

int main()
{
    Solution so;
    vector<int> nums{ 1,2,3,1 };
    cout << so.rob(nums) << endl;
    return 0;
}