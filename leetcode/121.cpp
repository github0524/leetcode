#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0]; 
        vector<int> dp(prices.size());
        for (int i = 1; i < prices.size(); i++)
        {
            m = min(prices[i],m);
            dp[i] = max(dp[i - 1], prices[i] - m);
        }
        return dp[prices.size() - 1];
    }
};