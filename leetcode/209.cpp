#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int count = 100001;
        int i=0, j=0;
        while (i <= j && j < nums.size())
        {
            if (j==0)
            {
                sum += nums[j];
            }
            if (sum >= target)
            {
                count = min(count, j - i + 1);
                sum -= nums[i];
                i++;
            }
            else
            {
                j++;
                if (j<nums.size())
                {
                    sum += nums[j];
                }

            }
        }
        return count > 100000 ? 0 : count;
    }
};

int main()
{
    Solution so;
    vector<int> nums{ 12,28,83,4,25,26,25,2,25,25,25,12 };
    cout << so.minSubArrayLen(213, nums) << endl;
    return 0;
}