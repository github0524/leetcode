
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() && i < j; i++, j--)
        {
            //char tmp;
            //tmp = s[i];
            //s[i] = s[j];
            //s[j] = tmp;
            swap(s[i], s[j]);
        }
    }
};

int main()
{
    Solution so;
    vector<char> s{ 'H','a','n','n','a','h' };
    so.reverseString(s);
    return 0;
}