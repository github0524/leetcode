#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rnum;
        sort(nums.begin(), nums.end());

        if (nums.size()<4)
        {
            return rnum;
        }
        for (int first = 0; first < nums.size(); first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            //这一句需要限制first的范围是size()-3
            //if ((long)nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target) {
            //    break;
            //}
            for (int second = first+1; second < nums.size(); second++)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                for (int three = second+1; three < nums.size(); three++)
                {
                    if (three > second + 1 && nums[three] == nums[three - 1])
                        continue;
                    int four = nums.size() - 1;
                    int sum = (long long)target - nums[first] - nums[second] - nums[three];

                    while (four > three)
                    {
                        if (nums[four]<=sum)
                        {
                            break;
                        }
                        four--;
                    }
                    if (four <= three)
                    {
                        continue;
                    }
                    if (nums[four]==sum)
                    {
                        rnum.push_back(vector<int>{nums[first], nums[second], nums[three], nums[four]});
                    }
                }
            }
        }

        return  rnum;
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
    vector<int> nums = { 2,1,0,-1 };
    Solution so;
    auto result = so.fourSum(nums,2);
    std::cout << "三数之和结果：\n" << result << std::endl;
    return 0;

}