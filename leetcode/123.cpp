#include <vector>
#include <iostream>
using namespace std;



//�ٷ��ⷨ����sell2��������ڶ��ε������׵Ļ��������ǵ�һ�κ͵ڶ���һ��Ļ���

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;//���������ʼ����������ˣ����ۼƵڶ�������֮���ֵ
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1 - prices[i]);//����sell1����ﵽ���֮���ٴλ���
            sell2 = max(sell2, prices[i] + buy2); //������ǵڶ��ε���󣬶��ǵ�һ�κ͵ڶ��ε����ĺͣ�buy2�Ѿ���һ������sell1�ĺ�
        }
        return sell2;
    }
};


//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int k = 2; // ����k��
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