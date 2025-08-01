#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//��ȷ��ֻҪ�ܹ���������չ����״̬�����ҳ����ƹ�ϵ����ô����ͺý����
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //����֮���״̬
        //״̬һ ����һֻ��Ʊ
        //״̬�� û�й�Ʊ�Ҳ����䶳��
        //״̬�� �䶳��
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