#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] ������ĸ����
 */

 // @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0, right = 0;
        for (int  i = 0; i < s.size(); i++)
        {
            right = max(right, hash[s[i] - 'a']);
            if (i==right)
            {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};
// @lc code=end