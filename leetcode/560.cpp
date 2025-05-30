#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		mp[0] = 1;
		int pre = 0,count = 0;
		for (auto num : nums)
		{
			pre += num;
			//pre[j−1]==pre[i]−k 简单的就是i 和j都必须存在于map中，所以要求存在才能加一
			if (mp.find(pre-k)!=mp.end())
			{
				count += mp[pre - k];
			}
			//这个条件应该在计数后面加上，因为pre[j−1]==pre[i]−k pre是现在的值，k是差值，在count计数之前，当前的pre应该在后面加入map
			mp[pre]++;
		}
		return count;
    }
};

int main()
{
	Solution so;
	vector<int> nums{ 1,1,1 };
	auto ret = so.subarraySum(nums,0);
	cout << ret;
	return 0;
}