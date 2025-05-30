#include <iostream>
#include <vector>
#include <algorithm>
/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //官方题解 贪心
        //1.如果存在，那么总剩余肯定大于0
        //2.从0开始到i，如果出现任意位置导致，当前剩余为负数，证明此区间内，没有一个点可以成为起点，出现这个情况只能是+++++++-，也就是说最后一个的亏空前面没有一个能补的，所以不可能在这里开始
        int totalsum=0;
        int cursum=0;
        int start = 0;
        int tmp=0;
        for (int i = 0; i < gas.size(); i++)
        {
            tmp = gas[i] - cost[i];
            totalsum = totalsum + tmp;
            cursum = cursum + tmp;
            if (cursum<0)
            {
                start = i + 1;
                cursum = 0;
            }
        }
        if (totalsum < 0) return -1;
        return start;
    }
};
/*循环太多超时*/
/*
 // @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //计算从每个油站出发到下一个油站还剩多少油，那些负数的肯定不是起点
        //空间换时间
        vector<int> rm;
        vector<int> head;
        int sum = 0;
        int flag = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            int tmp= gas[i] - cost[i];
            rm.push_back(tmp);
            if (tmp >= 0)
                head.push_back(i);
        }
        //从每个head向前走，一旦出现一个相加等于负数的，马上终止，换下一个
        for (int hd:head)
        {
            sum = 0;
            flag = 1;
            int new_hd;
            //循环次数i
            for (int i = 0; i < rm.size(); i++)
            {
                int a1 = hd + i;
                int a2 = rm.size();
                new_hd = a1 % a2;
                sum = sum + rm[new_hd];
                if (sum < 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                return (new_hd+1)%rm.size();
            }
        }
        return -1;
    }
};
// @lc code=end
*/
int main()
{
    Solution so;
    vector<int> nums = { 1,2,3,4,5 };
    vector<int> cost = { 3,4,5,1,2 };
    int k = 1;
    cout << so.canCompleteCircuit(nums, cost) << endl;
}