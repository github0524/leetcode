#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int numTrees(int n) {
//		int count = 0;
//		//和数字无关和数量有关
//		//dp0就是1 dp1就是1,dp2=2,dp3
//		//n=9 dp1=dp0+dp8 dp8buzhidao
//		vector<int> dp(n+1,0);
//		//错误想法，遍历的应该是长度，而不是变化的位置
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
			//固定总长度i的情况下，再考虑根节点位置
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