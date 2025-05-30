#include <iostream>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] ������Ʊ�����ʱ����������
 */

 // @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int minprice = prices[0];
        int result = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < minprice) minprice = prices[i];
            if (prices[i]-minprice-fee>0)
            {
                result += prices[i] - minprice - fee;
                minprice = prices[i] - fee; //�ؼ���һ�����������Ļ��ٴμ�ȥfee
            }
        }
        return result;
    }
};
// @lc code=end


int main()
{
    Solution so;
    vector<int> prices{ 1,3,2,8,4,9 };
    cout << so.maxProfit(prices, 2) << endl;
    return 0;
}