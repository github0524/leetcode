#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = nums[0];
        for (int i = 0; i <= range; i++)
        {
            range = max(range, nums[i]+i);
            if (range>=nums.size()-1)
                return true;
        }
        return false;
    }
};