#include <iostream>
#include <vector>
#include <string>

using namespace std;

//˫ָ�뷨
class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            //һ����Ϊ����
            result += extend(i, i, s.size(), s);
            result += extend(i, i + 1, s.size(), s);
        }
        return result;
    }
    //��չ
    int extend(int i, int j, int len, string& s)
    {
        int res = 0;
        while (i >= 0 && j < len && s[i] == s[j])
        {
            res++;
            //������չ
            i--;
            j++;
        }
        return res;
    }
};



//��̬�滮�ķ���
//class Solution {
//public:
//    int countSubstrings(string s) {
//        //dp ij ����[i,j]�������������Ƿ�Ϊ�����Ӵ����洢boolֵ
//        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
//        int result = 0;
//        for (int i = s.size()-1; i >=0 ; i--)
//        {
//            for (int j = i; j < s.size(); j++)
//            {
//                if (s[i]==s[j])
//                {
//                    //���ڻ���ͬһ��
//                    if (j-i<=1)
//                    {
//                        result++;
//                        dp[i][j] = true;
//                    }
//                    else if(dp[i+1][j-1])
//                    {
//                        result++;
//                        dp[i][j] = true;
//                    }
//                }
//            }
//        }
//        return result;
//
//    }
//};

int main()
{
    Solution so;
    cout << so.countSubstrings("aaa");
    return 0;
}