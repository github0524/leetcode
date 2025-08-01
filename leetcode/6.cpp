#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        //方向向下的话就是直接下，向上就是斜着上，但是根据返回意义，不需要相对位置，只需要在对应的数组的后面直接添加即可
        if (numRows <= 1) return s;
        vector<string> str(numRows, "");
        int down = true;
        int line = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (down)
            {
                if (line == numRows)
                {
                    down = false;
                    line = line - 2;
                }
                else
                {
                    str[line].push_back(s[i]);
                    line++;
                }
            }
            if (!down)
            {
                if (line == -1)
                {
                    down = true;
                    line = line + 2;
                }
                else {
                    str[line].push_back(s[i]);
                    line--;
                }
            }
        }
        string ret;
        for (int i = 0; i < numRows; i++)
        {
            ret = ret + str[i];
        }
        return ret;
    }
};

int main()
{
    Solution so;
    string s = so.convert("PAYPALISHIRING", 3);
    cout << s << endl;
}