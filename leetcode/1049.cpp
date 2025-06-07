#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//�����һ������֣���Ҫ�ֳ����룬Ȼ���������ôsum/2��������ı����������������װ�����֣���ʱ��sum-�����������������һ�������
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001, 0);
        int sum = 0;
        for (size_t i = 0; i < stones.size(); i++) sum += stones[i];
        int target = sum / 2;
        //����ÿ����Ʒ
        for (int i = 0; i < stones.size(); i++)
        {
            //��������
            //1.�������
            //2.j--
            for (int j=target; j >=stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]]+stones[i]);
            }
        }
        cout << sum << endl;
        cout << dp[target] << endl;
        //sum-dp[target]-dp[target],��һ�ε�����һ�룬�ڶ��ε�������֮������������<=��һ��
        return abs(dp[target] - (sum - dp[target]));
    }
};

int main()
{
    vector<int> stones{ 31,26,33,21,40 };
    Solution so;
    cout << so.lastStoneWeightII(stones) << endl;
    return 0;
}