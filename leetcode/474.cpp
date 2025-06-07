//1和0
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1,0)));
        int one = 0, zero = 0;
        //统计strs[i]里面的01数量
        for (auto s : strs[0])
        {
            if (s == '0')zero++;
            if (s == '1')one++;
        }
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (j>=zero&&k>=one)
                {
                    dp[0][j][k] = 1;
                }
            }
        }
        for (int i = 1; i < strs.size(); i++)
        {
            int one = 0, zero = 0;
            //统计strs[i]里面的01数量
            for (auto s : strs[i])
            {
                if (s == '0')zero++;
                if (s == '1')one++;
            }
            //m zero
            for (int j = 0; j <=m; j++)
            {
                //n one
                for (int k = 0; k <= n; k++)
                {
                    if (j>=zero&&k>=one)
                    {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zero][k - one] + 1);
                    }
                    else
                    {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }

                }
            }

        }
        return dp[strs.size()-1][m][n];
    }
};

/*官方题解*/
//class Solution {
//public:
//    vector<int> getZerosOnes(string& str) {
//        vector<int> zerosOnes(2);
//        int length = str.length();
//        for (int i = 0; i < length; i++) {
//            zerosOnes[str[i] - '0']++;
//        }
//        return zerosOnes;
//    }
//
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        int length = strs.size();
//        vector<vector<vector<int>>> dp(length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
//        for (int i = 1; i <= length; i++) {
//            vector<int>&& zerosOnes = getZerosOnes(strs[i - 1]);
//            int zeros = zerosOnes[0], ones = zerosOnes[1];
//            for (int j = 0; j <= m; j++) {
//                for (int k = 0; k <= n; k++) {
//                    dp[i][j][k] = dp[i - 1][j][k];
//                    if (j >= zeros && k >= ones) {
//                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
//                    }
//                }
//            }
//        }
//        return dp[length][m][n];
//    }
//};

int main()
{
    Solution so;
    vector<string> strs{ "10", "0", "1" };
    cout << so.findMaxForm(strs, 1, 1) << endl;
    return 0;
}