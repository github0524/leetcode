#include <string>

using namespace std;

class Solution {
public:
    void reverse(string& s, int left, int right)
    {
        for (; left < right; left++, right--)
        {
            swap(s[left], s[right]);
        }
    }
    string reverseStr(string s, int k) {
        //Ð¡ÓÚ2k
        if (s.size() < 2 * k)
        {
            reverse(s, 0, s.size() < k ? s.size() - 1 : k - 1);
            return s;
        }
        int remain = s.size();
        int time = 0;
        //int remain = s.size() - 2 * k;
        //N´Î2K
        while (remain >= 2 * k)
        {
            reverse(s, 0+time*2*k, k - 1+time*2*k);
            time++;
            remain = remain - 2 * k;
        }
        if (remain < k      && remain != 0) 
            reverse(s, time*2*k, s.size() - 1);
        if (remain < 2 * k  && remain >= k)  
            reverse(s, time*2*k, time*2*k+k-1);
        return s;
    }
};

int main()
{
    Solution so;
    string s("krmyfshbspcgtesxnnljhfursyissjnsocgdhgfxubewllxzqhpasguvlrxtkgatzfybprfmmfithphckksnvjkcvnsqgsgosfxc");
    so.reverseStr(s, 20);
    return 0;
}