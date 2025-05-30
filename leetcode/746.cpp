#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/*
����һ���������� cost ������ cost[i] �Ǵ�¥�ݵ� i ��̨����������Ҫ֧���ķ��á�һ����֧���˷��ã�����ѡ��������һ����������̨�ס�

�����ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�

������㲢���شﵽ¥�ݶ�������ͻ��ѡ�
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(0);
        for (int i = 2 ; i <= cost.size(); i++)
        {
            //if (cost.size()==2)
            //{
            //    return min(dp[0]+cost[0], dp[1]+cost[1]);
            //}
            dp.push_back( min(dp[i - 1]+cost[i-1], dp[i - 2]+cost[i-2]));
        }
        return dp[cost.size()];
    }
};

int main()
{
    vector<int> cost{1,100};
    Solution so;
    cout << so.minCostClimbingStairs(cost) << endl;
    return 0;
}