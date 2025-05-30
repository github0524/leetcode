/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

//官方解答的方法是通过从前往后，从次数的覆盖范围看，第一次的覆盖范围能不能到终点，不能就要被迫进行下一轮覆盖，从前往后遍历，第二轮能否覆盖，不能就要向下，如此推进。这样不需要考虑具体走法，只要判断出走的最低步数即可。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 // @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        //从最后一个往前,这里初始化值不能大于单个元素的最大值就可以，而是要大于整个数组的长度10000
        vector<int> step(nums.size(),INT32_MAX);
        if (nums.size() == 1)
            return 0;
        for ( int i = nums.size()-2;  i >= 0;  i--)
        {
            if (nums[i] + i >= nums.size() - 1)
                step[i] = 1;
            if (step[i]!=1)
            {
                for (int j = i; j <= nums[i] + i; j++)
                {
                    step[i] = min(step[i], step[j]+1);
                }
            }
        }
        return step[0];
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> nums = { 1,1,1,1,1,1 };
    cout << so.jump(nums) << endl;
}