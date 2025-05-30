#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

 // @lc code=start
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])  return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> tmp;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); i++)
        {
            tmp.insert(tmp.begin() + people[i][1], people[i]);
        }
        return tmp;
    }
};
// @lc code=end

int main() {
    Solution solution;

    // 测试用例
    vector<vector<int>> people = {
        {7, 0},
        {4, 4},
        {7, 1},
        {5, 0},
        {6, 1},
        {5, 2}
    };

    vector<vector<int>> result = solution.reconstructQueue(people);

    // 打印结果
    cout << "Reconstructed Queue:" << endl;
    for (const auto& person : result) {
        cout << "[" << person[0] << ", " << person[1] << "] ";
    }
    cout << endl;

    return 0;
}