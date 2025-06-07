#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i < target+1; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i>=nums[j])
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
            //for (auto num : nums)
            //{
            //    if (num<=i&&dp[i-num])
            //    {
            //        dp[i] += dp[i - num];
            //    }
            //}
        }
        return dp[target];
    }
};

//class Solution {
//public:
//    int combinationSum4(vector<int>& nums, int target) {
//        vector<int> dp(target + 1);
//        dp[0] = 1;
//        for (int i = 1; i <= target; i++) {
//            for (int& num : nums) {
//                if (num <= i && dp[i - num] <= INT_MAX - dp[i]) {
//                    dp[i] += dp[i - num];
//                }
//            }
//        }
//        return dp[target];
//    }
//};

int main()
{
    Solution so;
    vector<int> nums{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    cout << so.combinationSum4(nums,32) << endl;
    return 0;
}