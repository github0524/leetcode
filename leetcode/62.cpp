#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����

������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ����

���ܹ��ж�������ͬ��·����*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++) {
                if (i==1&&j==1)
                {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i ][j - 1] + dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};

int main()
{
    int m = 3, n = 2;
    Solution so;
    cout << so.uniquePaths(m,n) << endl;
    return 0;
}