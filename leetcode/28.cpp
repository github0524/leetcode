#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(needle.size()>haystack.size())return -1;
        for (int i = 0; i <= (haystack.size() - needle.size()); i++)
        {
            if (haystack[i] == needle[0])
            {
                int n = needle.size();
                int j = 1;
                int symbol = 0;
                while (j <= n - 1)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        symbol = 1;
                        break;
                    }
                    j++;
                }
                if (symbol == 0) return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution so;
    so.strStr("a", "a");
    return 0;
}