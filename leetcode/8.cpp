#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        //·Ö½×¶Î
        int season = 1;
        long long sum = 0;
        bool positive = true;
        for (auto c : s)
        {
            if (season == 1)
            {
                if (c == ' ') continue;
                season++;
            }
            //·ûºÅ
            if (season == 2)
            {
                if (c == '-' || c == '+')
                {
                    positive = c == '+' ? true : false;
                    season++;
                    continue;
                }
                season++;
            }
            //Êý×Ö
            if (season == 3)
            {
                if (c >= '0' && c <= '9')
                    season++;
                else
                    return 0;
            }
            if (season == 4)
            {
                if (c >= '0' && c <= '9')
                {
                    sum = sum * 10 + (c - '0');
                    continue;
                }
                else
                    break;
            }
        }
        //
        sum = positive ? sum : -sum;
        if (sum < INT_MIN) sum = INT_MIN;
        if (sum > INT_MAX) sum = INT_MAX;
        return sum;
    }
};

int main()
{
    Solution so;
    int ret = so.myAtoi("-91283472332");
    cout << ret << endl;
    cout << INT_MIN << endl;
    return 0;
}