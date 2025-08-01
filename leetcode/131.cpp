#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    bool ishuiwen(string& s, int left, int right)
    {
        while (left <= right)
        {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
public:
    void backtracking(string& s, int startIndex)
    {
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (ishuiwen(s, startIndex, i))
            {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }

    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};

int main()
{
    Solution so;
    string str("aab");
    so.backtracking(str, 0);
    return 0;
}