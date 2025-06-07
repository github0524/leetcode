#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    int numSquares(int n) {
		vector<int> nums{};
		for (int i = 1; i < n+1; i++)
		{
			if (i * i <= n) nums.push_back(i * i);
		}
		vector<int> dp(n + 1, 10001);
		dp[0] = 0;
		for (auto num : nums)
		{
			for (int j = num; j < n+1; j++)
			{
				dp[j] = min(dp[j], dp[j - num] + 1);
			}
		}
		return dp[n] == 10001 ? 10001 : dp[n];
    }
};

int main()
{
	Solution so;
	int n = 12;
	cout << so.numSquares(n) << endl;
}