#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode* left;
    ListNode* right;
    ListNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> order;
        for (auto num : nums)
        {
            order[num]++;
        }
        vector<pair<int, int>> vec;
        for (auto x:order)
        {
            vec.push_back(make_pair(x.first,x.second));
        }
        sort(vec.begin(), vec.end(), cmp);
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{ 2,2,3,1,1,1 };
    Solution so;
    so.topKFrequent(nums, 2);
    return 0;
}