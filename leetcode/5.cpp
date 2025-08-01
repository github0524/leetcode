#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int maxlen = 0;
        int left = 0, right = 0;
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j >=0; j--) {
                if (s[i]==s[j])
                {
                    if (i-j<=1)
                    {
                        dp[i][j] = i-j+1;
                        if (i-j+1 > maxlen) {
                            maxlen = i-j+1;
                            left = j;
                            right = i;
                        }
                    }
                    else if (dp[i - 1][j + 1] > 0)
                    {
                        dp[i][j] = dp[i - 1][j + 1] + 2;
                        if ((i-j+1) > maxlen) {
                            maxlen = i-j+1;
                            left = j ;
                            right = i;
                        }
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                    
                }
                else
                {
                    dp[i][j] = 0;
                }

            }
        }
        string str(s.begin() + left, s.begin() + right + 1);
        return str;
    }
};

int main()
{
    Solution so;
    string s("cbbd");
    so.longestPalindrome(s);
    return 0;
}