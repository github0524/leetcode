#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
		//i j ����[i,j]֮��������������
		//������1.�غ� 1 2.���� 2 3.>1 dp[i+1][j-1]+2
		//��������ȡ����һ��Ҳ��1 ʲôҲ���� �����ڵĿ��м�
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

//���������
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		vector<vector<int>> dp(s.size(), vector<int>(s.size()));
		for (int i = s.size() - 1; i >= 0; i--)
		{
			dp[i][i] = 1; //��ֵ
			for (int j = i + 1; j < s.size(); j++) //ֱ��+1����
			{

				if (s[i] == s[j])
				{
					dp[i][j] = dp[i + 1][j - 1] + 2;//���ڻ�������Ķ�����������
				}
				else
				{
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);//�����м�������ʵ�Ǳ�������
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