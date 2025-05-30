#include <vector>
#include <iostream>

using namespace std;

int n = 3;
//ÅÀÂ¥Ìİ
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