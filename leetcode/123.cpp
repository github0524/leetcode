#include <vector>
#include <iostream>
using namespace std;



//官方解法里面sell2并不代表第二次单独交易的获利，而是第一次和第二次一起的获利

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;//所以这个初始化就能理解了，是累计第二次买了之后的值
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1 - prices[i]);//首先sell1如果达到最大之后，再次积累
            sell2 = max(sell2, prices[i] + buy2); //这个不是第二次的最大，而是第一次和第二次的最大的和，buy2已经是一个加上sell1的和
        }
        return sell2;
    }
};


//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int k = 2; // 交易k次
//        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
//        for (int price : prices) {
//            for (int i = 1; i <= k; ++i) {
//                buy[i] = max(buy[i], sell[i - 1] - price);
//                sell[i] = max(sell[i], buy[i] + price);
//            }
//        }
//        return sell[k];
//    }
//};

int main()
{
    Solution so;
    vector<int> nums = { 1,2,4,2,5,7,2,4,9,0 };
    cout << so.maxProfit(nums) << endl;

}