#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        //dp从00点到 i j 点，最大的正方形面积是多少
        int maxside = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = (matrix[i][j] == '1') ? 1 : 0;
                }
                else {
                    if (matrix[i][j] == '0') dp[i][j] = 0;
                    else {
                        dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                    }
                }
                maxside = max(maxside, dp[i][j]);
            }
        }
        return maxside * maxside;
    }
};

int main()
{
    Solution so;
    vector<vector<char>> vec{ {'1','0','1','0','0'} ,{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
    int s = so.maximalSquare(vec);
    return s;
}