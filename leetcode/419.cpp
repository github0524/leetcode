#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //������ A-B = S
        //A+B = sum ,2A=S+sum A=(S+sum)/2
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        //����ǰ��Ĺ�ϵ��A��һ������������S+sumһ����һ��ż��������ֱ�ӷ���0 ����target�ľ���ֵ��һ��sum�޷��ﵽ��ֱֵ�ӷ���
        if ((target + sum) % 2 == 1 || sum < abs(target)) return 0;
        int new_target =abs(( target + sum )/ 2);
        vector<int> dp(new_target + 1, 0);
        //��ǰi�����ļ������ҳ���Ϊnew_target������ж��٣�������Ҫ��ǰ���Ѿ����ֵ��������+���뵱ǰԪ�صĿ����������
        dp[0] = 1; //ת��Ϊ1ά�������Ϊ0�Ŀ�������һ�֣����ǲ�ѡ
        for (int i = 0; i < nums.size(); i++)
        {

            for (int j= new_target;j>=nums[i];j--)
            {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[new_target];

    }
};

int main()
{
    Solution so;
    vector<int> nums{ 100 };
    cout << so.findTargetSumWays(nums, -50) << endl;
}