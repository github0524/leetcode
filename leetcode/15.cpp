#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret_nums;
        sort(nums.begin(), nums.end());
        int x, y, z;
        for ( x = 0; x < nums.size(); x++)
        {
            //不应该有重复的，不是指三个数不能有一样的，而是x枚举的时候，只有一种情况
            if (x>0&&nums[x]==nums[x-1])
            {
                continue;
            }
            z = nums.size() - 1;
            for ( y = x+1; y < nums.size(); y++)
            {
                //不应该有重复的，不是指三个数不能有一样的，而是y枚举的时候，只有一种情况
                //y的判断条件
                if (y > x+1 && nums[y] == nums[y - 1])
                {
                    continue;
                }
                //y<z的提示
                while (y<z&&(nums[y]+nums[z]>-nums[x]))
                {
                    z--;
                }
                if (y<z&&nums[y]+nums[z]==-nums[x])
                {
                    ret_nums.push_back({ nums[x],nums[y],nums[z] });
                }

            }

        }
        return ret_nums;
    }
};

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& vec) {
    os << "{\n";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << "  {";
        for (size_t j = 0; j < vec[i].size(); ++j) {
            os << vec[i][j];
            if (j != vec[i].size() - 1) os << ", ";
        }
        os << "}";
        if (i != vec.size() - 1) os << ",\n";
    }
    os << "\n}";
    return os;
}

int main()
{
    vector<int> nums = { 1,2,-2,-1 };
    Solution so;
    auto result = so.threeSum(nums);
    std::cout << "三数之和结果：\n" << result << std::endl;
    return 0;

}