#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


//map 用于映射下标
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ro;
        vector<int> ret{};
        for (int i = 0; i < nums.size(); i++)
        {
            if (ro.count(target - nums[i])) {
                return { ro[target - nums[i]],i };
            }
            ro[nums[i]] = i;
        }
        return ret;
    }
};

int main()
{
    vector<int> sums{ 3,2,4 };
    vector<int> ret;
    Solution so;
    ret = so.twoSum(sums,6);
    for (auto re : ret)
    {
        cout << re << endl;
    }
    return 0;
}