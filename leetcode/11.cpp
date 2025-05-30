#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//size的计算
//左右两个迭代器的变换方向
class Solution {
public:
    int maxArea(vector<int>& height) {
        auto left = height.begin();
        auto right = height.end()-1;
        int size = height.size()-1;
        int maxArea = size*min(*left,*right);
        while (left != right)
        {
            (*left < *right) ? left++ : right--;
            size--;
            int area = min(*left, *right) * (size);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

int main()
{
    Solution so;
    vector<int> arr{ 1,8,6,2,5,4,8,3,7 };
    int ret = so.maxArea(arr);
    cout << ret;
}