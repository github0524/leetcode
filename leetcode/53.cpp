//求和图像
//有单调递增的线段，这段就是求和最高
//没有单调递增的线段，最高点就是最大和

//不是求单调增的那段，而是曾哥曲线最低到最高上升的那段

//抽象一个图像为折线，有三种线，1.不变 2.上升 3.下降
//我们只需要关注上升的线段即可
//从左到右两两合并线段，能够保证局部是最短的，在这个局部中的两条直线有四个点，1L1H 1L2H 2L2H 判断出这三种情况的就可以，对应点用sum表示
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <iostream>
#include <vector>
using namespace std;

/*错误做法，很多反例没考虑清楚，这总解法还很麻烦*/
/*
 // @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //AB两线，LH分别代表低点和高点
        int AL = 0, AH, BL, BH;
        //一种情况 一直没有向上的，那么第一个点就是最高的
        int maxValue = nums[0];
        int isfirst = 0;
        int presum = nums[0];
        int cursum = 0;
        int prediff = 0;
        int curdiff = 0;
        int needcal = 0;
        if (nums.size() <= 1)
        {
            return maxValue;
        }
        //有向上的大于一次
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxValue = maxValue > nums[i + 1] ? maxValue : nums[i + 1];
            cursum = presum + nums[i + 1];
            curdiff = cursum - presum;
            if (isfirst == 0)
            {
                //上升点L
                if (curdiff > 0 && prediff <= 0)
                {
                    AL = presum;
                }
                //下降点H
                if (prediff > 0 && curdiff <= 0)
                {
                    AH = presum;
                    isfirst = 1;
                }
                //或者是终点
                if (curdiff > 0 && nums.size() - 2 == i)
                {
                    AH = cursum;
                    isfirst = 1;
                }
            }
            else
            {
                //上升点L
                if (curdiff > 0 && prediff <= 0)
                {
                    BL = presum;
                }
                //下降点H
                if (prediff > 0 && curdiff < 0)
                {
                    BH = presum;
                    needcal = 1;
                }
                //或者是终点
                if (curdiff > 0 && (i == nums.size() - 2))
                {
                    BH = cursum;
                    needcal = 1;
                }
            }
            if (needcal)
            {
                int L1, L2, L3;
                L1 = AH - AL;
                L2 = BH - BL;
                L3 = BH - AL;
                if (L2 >= L1 && L2 >= L3)
                {
                    AH = BH;
                    AL = BL;
                }
                if (L3 >= L1 && L3 >= L2)
                {
                    AH = BH;
                }
            }
            //更新趋势，0不管
            if (curdiff)
            {
                prediff = curdiff;
            }
            presum = cursum;
        }
        if (AL > 0)
        {
            return AH;
        }
        int ret = isfirst ? AH - AL : maxValue;
        if (ret < maxValue)
        {
            return maxValue;
        }
        return ret;
    }
};
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = 0;
        int result  = INT32_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if (count > result)
            {
                result = count;
            }
            if (count < 0)
            {
                count = 0;
            }
        }return  result;
    }
};
// @lc code=end
int main()
{
    Solution so;
    vector<int> nums = { -1 };
    cout << so.maxSubArray(nums) << endl;
}