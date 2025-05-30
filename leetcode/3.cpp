#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;
///*无重复字符的最长子串*/
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int i = 0;
//        int left = 0;
//        vector<char> win;
//        int len = 0;
//        for ( i = 0; i < s.length();)
//        {
//            if (find(win.begin(),win.end(),s[i])!=win.end())
//            {
//                win.erase(win.begin());
//                left++;
//            }
//            else
//            {
//                win.push_back(s[i]);
//                i++;
//            }
//            len = len > (i - left) ? len : (i - left);
//        }
//        return len;
//    }
//};



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> vec;
        int maxsize = 0;
        int size = 0;
        for (auto c : s)
        {
            while (true)
            {
                auto itor = find(vec.begin(), vec.end(), c);
                if (itor == vec.end())
                {
                    vec.push_back(c);
                    size++;
                    break;
                }
                else
                {
                    maxsize = max(maxsize, size);
                    vec.erase(vec.begin());
                    size--;
                }
            }
        }
        maxsize = max(maxsize, size);
        return maxsize;
    }
};


int main()
{
    string s = "au";
    Solution so;
    int len = so.lengthOfLongestSubstring(s);
    cout << len;
    return 0;
}