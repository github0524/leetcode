#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp i j Ϊ word1��i-1��β word2��j-1��β����С�༭����
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

        //��ʼ��Ӧ��������������Ϊ������һ���ǿյ�
        for (int i = 1; i <= len1; i++) dp[i][0] = i;
        for (int j = 1; j <= len2; j++) dp[0][j] = j;
        for (int i = 1; i <= len1; i++)
        {
            
            for (int j = 1; j <= len2; j++) {
                if (word1[i-1]==word2[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1,dp[i - 1][j - 1] + 1 });
                }
            }
        }
        return dp[len1][len2];
    }
};