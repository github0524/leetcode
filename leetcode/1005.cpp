#include <iostream>
#include <vector>
#include <algorithm>

//用时 23.34 min 

using namespace std;
class Solution {
public://2,-3,-1,5,-4 2
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //策略：K次，每次都是最小的取反
        int min=nums[0], key=0;
        int sum = 0;
        //k次取反
        for (int i = 0; i < k; i++)
        {
            //每次假设最小是第一个
            min = nums[0];
            key = 0;
            //遍历整个数组，找出最小的取反
            for (int j = 0; j < nums.size(); j++) {
                //此处min要即使更新
                if (min>=nums[j])
                {
                    key = j ;
                    min = nums[j];
                }
            }
            nums[key] = -nums[key];
        }
        for (int a : nums)  sum += a;
        return sum;
    }
};

int main()
{
    Solution so;
    vector<int> nums = {4,2,3};
    int k = 1;
    cout << so.largestSumAfterKNegations(nums,k)<< endl;
}