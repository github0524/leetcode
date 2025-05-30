#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

 // @lc code=start
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        if (intervals.size() <= 1) return 0;
        int left = intervals[0][0], right = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0]<right) /*此处没有= 边界不算重叠 [[1, 2], [2, 3], [3, 4], [1, 3]] */
            {
                count++;
                if (right>intervals[i][1])
                {
                    left = intervals[i][0];
                    right = intervals[i][1];
                }

            }
            else
            {
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        return count;
    }
};
// @lc code=end