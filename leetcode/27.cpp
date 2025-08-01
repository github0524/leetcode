
#include <iostream>
#include <vector>
#include <string>

using namespace std; 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        auto iter = find(nums.begin(), nums.end(), val);
        int count = 0;
        while (iter != nums.end())
        {
            nums.erase(iter);
            count++;
            iter = find(nums.begin(), nums.end(), val);
        }
        return n - count;
    }
};

int main()
{
    vector<int> nums{ 3,2,2,3 };
    Solution so;
    cout << so.removeElement(nums, 2) << endl;

}