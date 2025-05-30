#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


//[100,4,200,1,3,2]
//计算左右边界的时候
//哈希表中，查找到了，应该删除对应元素，不然后面如果有重复元素，会重复计算
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //hash
        unordered_set<int> hash;
        for (auto num:nums)
        {
            hash.insert(num);
        }
        //贪心策略
        int longest = 0;
        for (auto num:nums)
        {
            if (hash.find(num) == hash.end())
                continue;
            //本身也要删除
            hash.erase(num);
            int left = num-1;
            int right = num+1;
            //记得删除找到的元素
            while (hash.find(left) != hash.end())
            {
                hash.erase(left);
                left--;
            }
            while (hash.find(right) != hash.end())
            {
                hash.erase(right);
                right++;
            }
            //需要+1
            longest = max(longest, right - left-2+1);
        }
        return longest;
    }
};

//另一种解法
//已知最长的序列肯定是 1 2 3 4 5 这样连续的片段，同时，这个片段的起始点1左边肯定没有更小的数了
//所以我们排好了哈希表之后，就遍历数组，然后看这个数的左边即-1是不是没有数在哈希表内，如果没有我们就一直往右找，记录下半段的最长
//如果这个数不是最小，左边还有更小的，我们就跳过，继续找，这样可以大幅节约计算资源