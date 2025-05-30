#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

//����ˮ����
//�ڶ����½�������ʱˮ��
//���ڶ��߽磬���룬���µ�һ�߽�

//�����֣���һ������ߵ�ǰ���ڶ�������ߵ��
//class Solution {
//public:
//    int trap(vector<int>& height) {
//		if (height.size()<3)
//		{
//			return 0;
//		}
//		int maxvalue = 0;
//		int index = 0;
//		//�ҳ���ߵ�,��ߵ�����ж����ȡ���һ��
//		for (int i = 0; i < height.size(); i++)
//		{
//			if (height[i]>=maxvalue)
//			{
//				maxvalue = height[i];
//				index = i;
//			}
//		}
//
//		int left = 0, right = 1;
//		int trap = 0;
//		int tmppool = 0 ;
//		//��һ���֣�[0,index]
//		while (left < index+1 && right < index+1)
//		{
//			if (height[right]<height[left])
//			{
//				tmppool = tmppool + height[left] - height[right];
//			}
//			else
//			{
//				trap = trap + tmppool;
//				tmppool = 0;
//				left = right;
//			}
//			right++;
//		}
//		//�ڶ����֣�[index,size()-1]
//		// 
//		//���ұ������
//		tmppool = 0;
//		left = height.size()-1, right = height.size()-2;
//		while (left >index-1 && right >index-1)
//		{
//			if (height[right] < height[left])
//			{
//				tmppool = tmppool + height[left] - height[right];
//			}
//			else
//			{
//				trap = trap + tmppool;
//				tmppool = 0;
//				left = right;
//			}
//			right--;
//		}
//		
//		return trap;
//		
//    }
//};

class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		int leftpool = 0, rightpool = 0;
		int left = 0, right = height.size() - 1;
		int leftmax = 0, rightmax = 0;
		while (left < right)
		{
			leftmax = max(leftmax, height[left]);
			rightmax = max(rightmax, height[right]);
			if (height[left]< height[right])
			{
				ans += leftmax - height[left];
					left++;
			}
			else
			{
				ans += rightmax - height[right];
				right--;
			}
		}
		return ans;
	}
};

int main()
{
	Solution so;
	vector<int> nums = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int ret = so.trap(nums);
	cout << ret;
	return 0;
}