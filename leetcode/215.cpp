#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int quickselect(vector<int>& nums, int l, int r, int k) {
        if (l == r)
            return nums[k];
        int partition = nums[l], i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (nums[i] < partition);
            do j--; while (nums[j] > partition);
            if (i < j)
                swap(nums[i], nums[j]);
        }
        if (k <= j)return quickselect(nums, l, j, k);
        else return quickselect(nums, j + 1, r, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }
};

int main()
{
    Solution so;
    vector<int> nums{ 3,5,2,1,5,6,4,1 };
    int k = 2;
    return so.findKthLargest(nums, k);
}