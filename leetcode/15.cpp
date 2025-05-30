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
            //��Ӧ�����ظ��ģ�����ָ������������һ���ģ�����xö�ٵ�ʱ��ֻ��һ�����
            if (x>0&&nums[x]==nums[x-1])
            {
                continue;
            }
            z = nums.size() - 1;
            for ( y = x+1; y < nums.size(); y++)
            {
                //��Ӧ�����ظ��ģ�����ָ������������һ���ģ�����yö�ٵ�ʱ��ֻ��һ�����
                //y���ж�����
                if (y > x+1 && nums[y] == nums[y - 1])
                {
                    continue;
                }
                //y<z����ʾ
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
    std::cout << "����֮�ͽ����\n" << result << std::endl;
    return 0;

}