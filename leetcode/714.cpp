#include <iostream>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] ������Ʊ�����ʱ����������
 */

 // @lc code=start
//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee) {
        //int minprice = prices[0];
        //int result = 0;
        //for (int i = 1; i < prices.size(); i++)
        //{
        //    if (prices[i] < minprice) minprice = prices[i];
        //    if (prices[i]-minprice-fee>0)
        //    {
        //        result += prices[i] - minprice - fee;
        //        minprice = prices[i] - fee; //�ؼ���һ�����������Ļ��ٴμ�ȥfee
        //    }
        //}
        //return result;
//    }
//};
// @lc code=end

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //״̬ i��֮��
        //0 ���й�Ʊ
        //1 �����й�Ʊ
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[n - 1][1];
    }
};

int main()
{
    Solution so;
    vector<int> prices{ 1,3,2,8,4,9 };
    cout << so.maxProfit(prices, 2) << endl;
    return 0;
}