#include <vector>
#include <queue>

using namespace std;


//�������������ֵ
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        int n = nums.size();
//        //pair ����˲���Ĵ������ȶ��дӴ�С����
//        priority_queue<pair<int, int>> q;
//        for (int i = 0; i < k; ++i) {
//            q.emplace(nums[i], i);
//        }
//        vector<int> ans = { q.top().first };
//        for (int i = k; i < n; ++i) {
//            q.emplace(nums[i], i);
//            while (q.top().second <= i - k) {
//                q.pop();
//            }
//            ans.push_back(q.top().first);
//        }
//        return ans;
//    }
//};

//�������������ֵ
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>> q;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            q.emplace(nums[i], i);
        }
        ans.push_back(q.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            q.emplace(nums[i], i);
            //<=
            while(q.top().second<=i-k)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{ 1,-1 };
    Solution so;
    so.maxSlidingWindow(nums, 1);
    return 0;
}