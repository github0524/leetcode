#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        int sum = 0;
//        if (amount == 0) return 0;
//        vector<int> dp(amount + 1);
//        //��ȫ��������
//        for (int i = 1; i <= amount; i++)
//        {
//            for (int j = 0; j < coins.size(); j++)
//            {
//                //�����ǿ��Լ����
//                if (i==coins[j])
//                {
//                    dp[i] = dp[i]==0?1:min(dp[i], 1);
//
//                }
//                if (i>coins[j])
//                {
//                    dp[i] = dp[i - coins[j]] == 0 ? dp[i] : dp[i]!=0 ? min(dp[i], dp[i - coins[j]] + 1): dp[i - coins[j]] + 1;
//                }
//            }
//        }
//        return dp[amount] == 0 ? -1 : dp[amount];
//    }
//};

//������������֮���Ը����ô�鷳��������Ϊ��ʼ�����ˣ���Ŀ����amount<=10000����������ȫ����1���Ҳ���ᳬ��INT_MAX�������
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sum = 0;
        if (amount == 0) return 0;
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        //��ȫ��������
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                //�����ǿ��Լ����
                if (i >= coins[j]&&dp[i-coins[j]]!=INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]]+1);

                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main()
{
    vector<int> coin{ 1,2,5 };
    int amount = 11;
    Solution so;
    cout << so.coinChange(coin,amount) << endl;
	return 0;
}