#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//正确，只要能够想出，今日过后的状态，且找出递推关系，那么问题就好解决。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //今天之后的状态
        //状态一 持有一只股票
        //状态二 没有股票且不是冷冻期
        //状态三 冷冻期
        vector<vector<int>> dp(prices.size(), vector<int>(3));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1],dp[i-1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};

int main()
{
	
}