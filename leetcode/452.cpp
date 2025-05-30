#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

 // @lc code=start
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int left = points[0][0], right = points[0][1];
        int count = 1;
        for (int i = 0; i < points.size(); i++)
        {
            if (right<points[i][0])
            {
                count++;
                left = points[i][0];
                right =  points[i][1];
            }
            left = points[i][0];
            right = min(right, points[i][1]);
        }
        return count;
    }
};
// @lc code=end




int main()
{

}