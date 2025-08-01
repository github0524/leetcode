#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        //�漰��S�е�ѡ�벻ѡ������
        //dp ij ������si��tjƥ���ܵĿ����ԣ����У�����BAA BA������ƥ�����ǻᷢ�ֵ�һ��A�ǿ��ܲ�ƥ��ģ������ڶ���A��ƥ��
        //��������ҲҪ��¼��ʹ��ʹ�õ�һ�����ֵ�A�Ŀ�����
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