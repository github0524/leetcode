/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

//贪心 其实只需要把两天两天之间的价格相减，得到的价格的正数的总和就是最大利润，没有就是默认为0；

#include <iostream>
#include <vector>
using namespace std;
 // @lc code=start
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int prediff = 0, curdiff = 0; 
//        int buy=0, sell=0, profit=0;
//        for (int i = 0; i < prices.size()-1; i++)
//        {
//            curdiff = prices[i + 1] - prices[i];
//            if (curdiff>0&&prediff<=0)
//            {
//                buy = prices[i];
//                sell = 1;
//            }
//            //curdiff < 0 && prediff >= 0,直接这样会导致一开始下降也被算进去
//            if (curdiff<0&&prediff>=0&&sell==1)
//            {
//                profit = profit + prices[i] - buy;
//                sell = 0;
//            }
//            if (sell&& i == prices.size() - 2)
//            {
//                    profit = profit + prices[i+1] - buy;
//                    sell = 0;
//            }
//            if (curdiff)
//            {
//                prediff = curdiff;
//            }
//        }
//        return profit;
//    }
//};
//// @lc code=end

//动态规划
//dp[i][j]表示第i天的收益状况 j 0表示没有持有，1表示持有了
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        int dp[n][2];
//    }
//};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};



int main()
{
    Solution so;
    vector<int> nums = { 7,1,5,3,6,4 };
    cout << so.maxProfit(nums) << endl;

}