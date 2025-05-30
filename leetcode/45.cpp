/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] ��Ծ��Ϸ II
 */

//�ٷ����ķ�����ͨ����ǰ���󣬴Ӵ����ĸ��Ƿ�Χ������һ�εĸ��Ƿ�Χ�ܲ��ܵ��յ㣬���ܾ�Ҫ���Ƚ�����һ�ָ��ǣ���ǰ����������ڶ����ܷ񸲸ǣ����ܾ�Ҫ���£�����ƽ�����������Ҫ���Ǿ����߷���ֻҪ�жϳ��ߵ���Ͳ������ɡ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 // @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        //�����һ����ǰ,�����ʼ��ֵ���ܴ��ڵ���Ԫ�ص����ֵ�Ϳ��ԣ�����Ҫ������������ĳ���10000
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