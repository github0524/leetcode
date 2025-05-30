#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/*
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(0);
        for (int i = 2 ; i <= cost.size(); i++)
        {
            //if (cost.size()==2)
            //{
            //    return min(dp[0]+cost[0], dp[1]+cost[1]);
            //}
            dp.push_back( min(dp[i - 1]+cost[i-1], dp[i - 2]+cost[i-2]));
        }
        return dp[cost.size()];
    }
};

int main()
{
    vector<int> cost{1,100};
    Solution so;
    cout << so.minCostClimbingStairs(cost) << endl;
    return 0;
}