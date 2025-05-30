#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*官方题解，考查的就是排序，还有时间复杂度，奇偶size的中间数查找*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto begin2 = nums2.begin();
        vector<int> nums3 = nums1;
        while (begin2!=nums2.end())
        {
            nums3.push_back(*begin2);
            begin2++;
        }
        sort(nums3.begin(), nums3.end());
        
        if (nums3.size() % 2 == 0)
        {
            int mid = nums3.size() / 2;
            return (nums3[mid] + nums3[mid - 1]) / 2.0;
        }
        else
        {
            int mid = (nums3.size()+1) / 2;
            return nums3[mid - 1];
        }
    }
};

int main()
{
    Solution so;
    vector<int> nums1{1,2};
    vector<int> nums2{3,4};
    double ret = so.findMedianSortedArrays(nums1,nums2);
    cout << ret << endl;
}