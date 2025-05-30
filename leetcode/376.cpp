/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

//1.画图能发现只要能找出全部单调的节点，去除这个单调方向上的中间节点即可，实际上只需返回数量，所以只统计单调次数+1即可
//2.一个元素也是摆动序列，所以是长度为1
//3.注意单调的判断条件，1.上一次为0时，此次不为0即可 2.上次与此次的方向乘积是一个负数，代表两个都不相等 ，但是如果就这两个条件遇到 2，1，1，0 判断出长度3，因为1-1=0 下一次不为0，
//会被计算在内，但是我们知道其实单调性并未改变，怎么解决呢？在计算的时候，凡是计算结果等于0的，direct这个保存之前单调性的都不更新，因为=0代表不改变单调性，这样就能完美解决这个问题
#include <vector>
#include <iostream>
using namespace std;
 // @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int direct = 0;
        int end=0;
        auto begin = nums.begin();
        int tmp_direct = 0;
        if (nums.size()==1)
        {
            return 1;
        }
        //为了方便元素计算防止越界，从第二个开始算
        for (begin++; begin!=nums.end(); begin++)
        {
            tmp_direct = (*begin) - (*(begin-1));
            //第二个条件只适合一开始一直是0，然后改变的情况
            //官方写法 (curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)，从最本质出发，其中如果当前的diff=0，preDiff也是不会更新的，这条公式也就正好满足
            if ((tmp_direct * direct <0) || (direct==0&&tmp_direct!=0))
            {
                end++;
            }
            if (tmp_direct > 0)
            {
                direct = 1;
            }
            if (tmp_direct < 0)
            {
                direct = -1;
            }
            //这一段不能加上面有说明，=0不改变单调性，加了下面一段会导致误判单调改变
            //if (tmp_direct == 0)
            //{
            //    direct = 0;
            //}
        }
        return end+1;
    }
};
// @lc code=end

int main()
{
    Solution so;
    vector<int> nums = { 2,1,1,0 };
    cout << so.wiggleMaxLength(nums) << endl;
    return 0;
}
