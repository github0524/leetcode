#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        //涉及到S中的选与不选的问题
        //dp ij 代表用si和tj匹配能的可能性，其中，例如BAA BA这样的匹配我们会发现第一个A是可能不匹配的，留到第二个A再匹配
        //但是我们也要记录即使不使用第一个出现的A的可能性
        vector<vector<unsigned long long>> dp(s.size() + 1, vector<unsigned long long>(t.size() + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= t.size(); j++)
            {
                dp[0][j] = 0;
                if (s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};

int main()
{

}