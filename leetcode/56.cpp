#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

 // @lc code=start
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()<=1)
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0]>right)
            {
                result.push_back({ left,right });
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else
            {
                right = max(right, intervals[i][1]);
            }

        }
        result.push_back({ left,right });
        return result;
    }
};
// @lc code=end
