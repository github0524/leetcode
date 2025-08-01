#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        //�������µĻ�����ֱ���£����Ͼ���б���ϣ����Ǹ��ݷ������壬����Ҫ���λ�ã�ֻ��Ҫ�ڶ�Ӧ������ĺ���ֱ����Ӽ���
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