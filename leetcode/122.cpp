/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] ������Ʊ�����ʱ�� II
 */

//̰�� ��ʵֻ��Ҫ����������֮��ļ۸�������õ��ļ۸���������ܺ;����������û�о���Ĭ��Ϊ0��

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
//            //curdiff < 0 && prediff >= 0,ֱ�������ᵼ��һ��ʼ�½�Ҳ�����ȥ
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

//��̬�滮
//dp[i][j]��ʾ��i�������״�� j 0��ʾû�г��У�1��ʾ������
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