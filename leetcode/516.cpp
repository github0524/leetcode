#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
		//i j 代表[i,j]之间的最长回文子序列
		//如果相等1.重合 1 2.靠近 2 3.>1 dp[i+1][j-1]+2
		//如果不相等取其中一个也是1 什么也不做 不相邻的看中间
		//i<=j
		vector<vector<int>> dp(s.size(), vector<int>(s.size()));
		for (int i = s.size()-1; i >=0; i--)
		{
			for (int  j = i; j < s.size(); j++)
			{
				if (s[i]==s[j])
				{
					if (i == j) dp[i][j] = 1;
					if (j - i == 1) dp[i][j] = 2;
					if (j-i>1)
					{
						dp[i][j] = dp[i + 1][j - 1] + 2;
					}
				}
				else
				{
					dp[i][j] = max({ dp[i + 1][j],dp[i + 1][j - 1],dp[i][j - 1] });
				}
				
			}
		}

		return dp[0][s.size() - 1];
    }
};

//这样更简洁
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		vector<vector<int>> dp(s.size(), vector<int>(s.size()));
		for (int i = s.size() - 1; i >= 0; i--)
		{
			dp[i][i] = 1; //赋值
			for (int j = i + 1; j < s.size(); j++) //直接+1起算
			{

				if (s[i] == s[j])
				{
					dp[i][j] = dp[i + 1][j - 1] + 2;//相邻或者相隔的都是这种做法
				}
				else
				{
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);//上面中间的情况其实是被包含的
				}

			}
		}
		return dp[0][s.size() - 1];
	}
};

int main()
{
	Solution so;
	cout << so.longestPalindromeSubseq("aabaaba") << endl;
}