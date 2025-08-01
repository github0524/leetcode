#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

//双端队列
class Solution {
public:
    // 判断是否为运算符（仅接受单个字符的运算符）
    bool isOperator(const std::string& str) {
        return str.length() == 1 && (str == "+" || str == "-" || str == "*" || str == "/");
    }

    string calculate(string s1, string s2, string s3)
    {
        int x = stoi(s1);
        int y = stoi(s2);
        int op = 0;
        int sum = 0;
        if (s3 == "+")
            op = 1;
        if (s3 == "-")
            op = 2;
        if (s3 == "*")
            op = 3;
        if (s3 == "/")
            op = 4;

        switch (op)
        {
        case 1:
            sum = x + y;
            break;
        case 2:
            sum = x - y;
            break;
        case 3:
            sum = x * y;
            break;
        case 4:
            sum = x / y;
            break;
        }
        return to_string(sum);
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for (auto str : tokens)
        {
            if (isOperator(str))
            {
                string s2 = stk.top();
                stk.pop();
                string s1 = stk.top();
                stk.pop();
                string sum = calculate(s1, s2, str);
                stk.push(sum);
            }
            else
            {
                stk.push(str);
            }
        }
        return stoi(stk.top());
    }
};

//2 1 + 3 *
//3 3 *
//

int main()
{
    Solution so;
    vector<string> tokens{ "2","1","+","3","*" };
    istringstream iss(tokens[0]);
    ostringstream oss ;
    oss << iss;
    cout << iss << endl;
    cout << so.evalRPN(tokens);
    return 0;
}