#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int numTrees(int n) {
//		int count = 0;
//		//�������޹غ������й�
//		//dp0����1 dp1����1,dp2=2,dp3
//		//n=9 dp1=dp0+dp8 dp8buzhidao
//		vector<int> dp(n+1,0);
//		//�����뷨��������Ӧ���ǳ��ȣ������Ǳ仯��λ��
//		for (int i = 1; i <= n; i++)
//		{
//			dp[i] = dp[i - 1] * dp[n - i];
//		}
//		return count;
//    }
//};


class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i < n+1; i++)
		{
			//�̶��ܳ���i������£��ٿ��Ǹ��ڵ�λ��
			for (int j = 1; j < i+1; j++)
			{
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}
		return dp[n];
	}
};

int main()
{
	Solution so;
	cout << so.numTrees(3) << endl;
	return 0;
}