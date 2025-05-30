#include <iostream>
#include <vector>
#include <algorithm>
/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] ����վ
 */
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //�ٷ���� ̰��
        //1.������ڣ���ô��ʣ��϶�����0
        //2.��0��ʼ��i�������������λ�õ��£���ǰʣ��Ϊ������֤���������ڣ�û��һ������Գ�Ϊ��㣬����������ֻ����+++++++-��Ҳ����˵���һ���Ŀ���ǰ��û��һ���ܲ��ģ����Բ����������￪ʼ
        int totalsum=0;
        int cursum=0;
        int start = 0;
        int tmp=0;
        for (int i = 0; i < gas.size(); i++)
        {
            tmp = gas[i] - cost[i];
            totalsum = totalsum + tmp;
            cursum = cursum + tmp;
            if (cursum<0)
            {
                start = i + 1;
                cursum = 0;
            }
        }
        if (totalsum < 0) return -1;
        return start;
    }
};
/*ѭ��̫�೬ʱ*/
/*
 // @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //�����ÿ����վ��������һ����վ��ʣ�����ͣ���Щ�����Ŀ϶��������
        //�ռ任ʱ��
        vector<int> rm;
        vector<int> head;
        int sum = 0;
        int flag = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            int tmp= gas[i] - cost[i];
            rm.push_back(tmp);
            if (tmp >= 0)
                head.push_back(i);
        }
        //��ÿ��head��ǰ�ߣ�һ������һ����ӵ��ڸ����ģ�������ֹ������һ��
        for (int hd:head)
        {
            sum = 0;
            flag = 1;
            int new_hd;
            //ѭ������i
            for (int i = 0; i < rm.size(); i++)
            {
                int a1 = hd + i;
                int a2 = rm.size();
                new_hd = a1 % a2;
                sum = sum + rm[new_hd];
                if (sum < 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                return (new_hd+1)%rm.size();
            }
        }
        return -1;
    }
};
// @lc code=end
*/
int main()
{
    Solution so;
    vector<int> nums = { 1,2,3,4,5 };
    vector<int> cost = { 3,4,5,1,2 };
    int k = 1;
    cout << so.canCompleteCircuit(nums, cost) << endl;
}