
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

 // @lc code=start
/*
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int m;
        int i = 0;
        int minm = 10;
        int save = 0;
        while (true)
        {
            if (n == 0) break;
            minm = min(n % 10, minm);
            if (i > 0)m += minm * pow(10, i);
            else m = minm;
            save = n;
            n /= 10;
            i++;
        }
        int tmp = save * pow(10, i - 1) - 1;
        return max(m,tmp);
    }
};*/
// @lc code=end
/*这道题的关键在于从前往后，也就是从高位到低位，一旦发现如98，这样第一个比第二个大的数，第一个数-1（这时候已经满足<=N这个条件了，后面的全部填9，就是局部最优了）*/
/*从前向后遍历的话，遇到strNum[i - 1] > strNum[i]的情况，让strNum[i - 1]减⼀，但此时如果
strNum[i - 1]减⼀了，可能又⼩于strNum[i - 2]。
这么说有点抽象，举个例⼦，数字：332，从前向后遍历的话，那么就把变成了329，此时2又
⼩于了第⼀位的3了，真正的结果应该是299。
所以从前后向遍历会改变已经遍历过的结果！
那么从后向前遍历，就可以重复利⽤上次⽐较得出的结果了，从后向前遍历332的数值变化
为：332 -> 329 -> 299*/
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int flag = s.size();
        for (int i =  s.size() - 1 ; i > 0; i--)
        {
            if (s[i] < s[i - 1])
            {
                flag = i;
                s[i - 1]--;
            }
        }
        for (int i = s.size() - 1; i>=flag ; i--)
        {
            s[i] = '9';
        }
        return stoi(s);
    }
};


int main()
{
    int n = 9;
    Solution so;
    cout << so.monotoneIncreasingDigits(n) << endl;
    return 0;

}