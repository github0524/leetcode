#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        vector < vector<int>> dp(n+1, vector<int>(obstacleGrid[0].size()+1,0));
        
        for (int i = 1; i <= obstacleGrid.size(); i++)
        {
            for (int j = 1; j <= obstacleGrid[0].size(); j++)
            {
                if (i==1&&j==1)
                {
                    dp[i][j] = 1;
                    if (obstacleGrid[i - 1][j - 1] == 1)
                    {
                        dp[i][j] = 0;
                        continue;
                    }
                    continue;
                }
                if (obstacleGrid[i-1][j-1]==1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        return dp[obstacleGrid.size()][obstacleGrid[0].size()];
        
    }
};


int main()
{
    vector<vector<int>> grid{ 1 };
    Solution so;
    cout << so.uniquePathsWithObstacles(grid) << endl;
    return 0;
}