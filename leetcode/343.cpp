#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
对于正整数 n，当 n≥2 时，可以拆分成至少两个正整数的和。令 x 是拆分出的第一个正整数，则剩下的部分是 n−x，n−x 可以不继续拆分，或者继续拆分成至少两个正整数的和。由于每个正整数对应的最大乘积取决于比它小的正整数对应的最大乘积，因此可以使用动态规划求解。

创建数组 dp，其中 dp[i] 表示将正整数 i 拆分成至少两个正整数的和之后，这些正整数的最大乘积。特别地，0 不是正整数，1 是最小的正整数，0 和 1 都不能拆分，因此 dp[0]=dp[1]=0
*/

/*
这道题的关键就在于，j×(i−j)、j×dp[i−j]这两种可能，其实都是已知的，只是dp[i-j]需要用到动态规划去求解
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        //从3开始
        for (int i = 3; i <= n; i++)
        {
            //这里j的范围应该用i来表示，不能用j<n因为比如n是10 i是3,那么3-j可能是一个负数
            for (int j = 1; j < i; j++)
            {
                dp[i]=max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
            cout << "dp[" << i << "]" << " " << dp[i] << endl;
        }
        return dp[n];
    }
};

//也可以这样直接连dp[2]都自己推导
//class Solution {
//public:
//    int integerBreak(int n) {
//        vector<int> dp(n + 1);
//        for (int i = 3; i <= n; i++)
//        {
//            //这里j的范围应该用i来表示，不能用j<n因为比如n是10 i是3,那么3-j可能是一个负数
//            for (int j = 1; j < i; j++)
//            {
//                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
//            }
//        }
//        return dp[n];
//    }
//};


int main()
{
    int n = 10;
    Solution so;
    cout << so.integerBreak(n) << endl;
    return 0;
}