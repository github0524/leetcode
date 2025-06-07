#include <vector>
#include <iostream>

using namespace std;

int n = 3;
//ÅÀÂ¥ÌÝ
int main() {
	vector<int> dp;
	for (int i= 0; i<=n;i++)
	{
		dp.push_back(0);
		if (i <= 2)
		{
			dp[i] = i;
			continue;
		}
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << endl;

	return 0;
}

//class Solution {
//public:
//	int count(int n)
//	{
//		vector<int> nums{ 1,2 };
//		vector<int> dp(n + 1);
//		dp[0] = 1;
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 0; j < 2; j++) {
//				if (i>=nums[j])
//				{
//					dp[i] = dp[i] + dp[i - nums[j]];
//				}
//			}
//		}
//		return dp[n];
//	}
//};
//
//int main()
//{
//	Solution so;
//	cout << so.count(3) << endl;
//}