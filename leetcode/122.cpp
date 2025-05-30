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
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prediff = 0, curdiff = 0; 
        int buy=0, sell=0, profit=0;
        for (int i = 0; i < prices.size()-1; i++)
        {
            curdiff = prices[i + 1] - prices[i];
            if (curdiff>0&&prediff<=0)
            {
                buy = prices[i];
                sell = 1;
            }
            //curdiff < 0 && prediff >= 0,ֱ�������ᵼ��һ��ʼ�½�Ҳ�����ȥ
            if (curdiff<0&&prediff>=0&&sell==1)
            {
                profit = profit + prices[i] - buy;
                sell = 0;
            }
            if (sell&& i == prices.size() - 2)
            {
                    profit = profit + prices[i+1] - buy;
                    sell = 0;
            }
            if (curdiff)
            {
                prediff = curdiff;
            }
        }
        return profit;
    }
};
// @lc code=end

int main()
{
    Solution so;
    vector<int> nums = { 7,6,4,3,1 };
    cout << so.maxProfit(nums) << endl;

}