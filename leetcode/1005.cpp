#include <iostream>
#include <vector>
#include <algorithm>

//��ʱ 23.34 min 

using namespace std;
class Solution {
public://2,-3,-1,5,-4 2
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //���ԣ�K�Σ�ÿ�ζ�����С��ȡ��
        int min=nums[0], key=0;
        int sum = 0;
        //k��ȡ��
        for (int i = 0; i < k; i++)
        {
            //ÿ�μ�����С�ǵ�һ��
            min = nums[0];
            key = 0;
            //�����������飬�ҳ���С��ȡ��
            for (int j = 0; j < nums.size(); j++) {
                //�˴�minҪ��ʹ����
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