#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //���ص����±�
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.count(mp[target-nums[i]]))
            {
                return { mp[target - nums[i]],i };
            }
            //�洢��ǰֵ���±�
            mp[nums[i]] = i;
        }
    }
};