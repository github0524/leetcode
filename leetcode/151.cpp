#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> tmpstr;
        string tmp;
        for (int i = 0; i < s.size();i++)
        {
            if (s[i] == ' ' && !tmp.empty())
            {
                tmpstr.push_back(tmp);
                tmp.clear();
            }
            if (s[i] != ' ')
            {
                tmp = tmp + s[i];
            }
            if (i == s.size() - 1 && !tmp.empty())
            {
                tmpstr.push_back(tmp);
                tmp.clear();
            }
        }
        for (int i = tmpstr.size() - 1; i >= 0; i--)
        {
            tmp = tmp + tmpstr[i];
            if (i != 0)
                tmp = tmp + ' ';
        }
        return tmp;
    }
};

int main()
{
    Solution so;
    auto s = so.reverseWords("the sky is blue");
    cout << s << endl;
    return 0;
}