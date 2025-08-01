#include <iostream>
#include <vector>
#include <string>

using namespace std;

//双指针法
class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            //一个数为中心
            result += extend(i, i, s.size(), s);
            result += extend(i, i + 1, s.size(), s);
        }
        return result;
    }
    //拓展
    int extend(int i, int j, int len, string& s)
    {
        int res = 0;
        while (i >= 0 && j < len && s[i] == s[j])
        {
            res++;
            //向外扩展
            i--;
            j++;
        }
        return res;
    }
};



//动态规划的方法
//class Solution {
//public:
//    int countSubstrings(string s) {
//        //dp ij 就是[i,j]这个区间里面的是否为回文子串，存储bool值
//        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
//        int result = 0;
//        for (int i = s.size()-1; i >=0 ; i--)
//        {
//            for (int j = i; j < s.size(); j++)
//            {
//                if (s[i]==s[j])
//                {
//                    //相邻或者同一个
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