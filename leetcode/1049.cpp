#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//抽象成一大堆数字，需要分成两半，然后相减，那么sum/2就是理想的背包最大重量，里面装入数字，到时候sum-背包最大总量等于另一半的重量
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001, 0);
        int sum = 0;
        for (size_t i = 0; i < stones.size(); i++) sum += stones[i];
        int target = sum / 2;
        //遍历每样物品
        for (int i = 0; i < stones.size(); i++)
        {
            //遍历背包
            //1.反向遍历
            //2.j--
            for (int j=target; j >=stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]]+stones[i]);
            }
        }
        cout << sum << endl;
        cout << dp[target] << endl;
        //sum-dp[target]-dp[target],第一次等于另一半，第二次等于两者之差，背包里面这个<=另一半
        return abs(dp[target] - (sum - dp[target]));
    }
};

int main()
{
    vector<int> stones{ 31,26,33,21,40 };
    Solution so;
    cout << so.lastStoneWeightII(stones) << endl;
    return 0;
}