#include <vector>
#include <iostream>


using namespace std;
//��ϸ���������� ��ȵĲ���
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //01��������
        int n = nums.size();
        vector<int> dp(n+1,INT_MAX);
        //dp�������ܹ��ﵽi����Сֵ��˭
        dp[0] = INT_MIN;
        dp[1] = nums[0];
        int len = 1;
        //����
        for (int i = 1; i < n; i++)
        {
            //����
            for (int j = 1; j <= i+1; j++)
            {
                if (nums[i]<dp[j]&&nums[i]>dp[j-1])
                {
                    dp[j] = nums[i];
                    len = max(len, j);
                }
            }
        }
        return len;
    }
};