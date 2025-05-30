#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //返回的是下标
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.count(mp[target-nums[i]]))
            {
                return { mp[target - nums[i]],i };
            }
            //存储当前值的下标
            mp[nums[i]] = i;
        }
    }
};