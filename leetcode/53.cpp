//���ͼ��
//�е����������߶Σ���ξ���������
//û�е����������߶Σ���ߵ��������

//�����󵥵������ǶΣ���������������͵�����������Ƕ�

//����һ��ͼ��Ϊ���ߣ��������ߣ�1.���� 2.���� 3.�½�
//����ֻ��Ҫ��ע�������߶μ���
//�����������ϲ��߶Σ��ܹ���֤�ֲ�����̵ģ�������ֲ��е�����ֱ�����ĸ��㣬1L1H 1L2H 2L2H �жϳ�����������ľͿ��ԣ���Ӧ����sum��ʾ
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] ����������
 */
#include <iostream>
#include <vector>
using namespace std;

/*�����������ܶ෴��û������������ܽⷨ�����鷳*/
/*
 // @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //AB���ߣ�LH�ֱ����͵�͸ߵ�
        int AL = 0, AH, BL, BH;
        //һ����� һֱû�����ϵģ���ô��һ���������ߵ�
        int maxValue = nums[0];
        int isfirst = 0;
        int presum = nums[0];
        int cursum = 0;
        int prediff = 0;
        int curdiff = 0;
        int needcal = 0;
        if (nums.size() <= 1)
        {
            return maxValue;
        }
        //�����ϵĴ���һ��
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxValue = maxValue > nums[i + 1] ? maxValue : nums[i + 1];
            cursum = presum + nums[i + 1];
            curdiff = cursum - presum;
            if (isfirst == 0)
            {
                //������L
                if (curdiff > 0 && prediff <= 0)
                {
                    AL = presum;
                }
                //�½���H
                if (prediff > 0 && curdiff <= 0)
                {
                    AH = presum;
                    isfirst = 1;
                }
                //�������յ�
                if (curdiff > 0 && nums.size() - 2 == i)
                {
                    AH = cursum;
                    isfirst = 1;
                }
            }
            else
            {
                //������L
                if (curdiff > 0 && prediff <= 0)
                {
                    BL = presum;
                }
                //�½���H
                if (prediff > 0 && curdiff < 0)
                {
                    BH = presum;
                    needcal = 1;
                }
                //�������յ�
                if (curdiff > 0 && (i == nums.size() - 2))
                {
                    BH = cursum;
                    needcal = 1;
                }
            }
            if (needcal)
            {
                int L1, L2, L3;
                L1 = AH - AL;
                L2 = BH - BL;
                L3 = BH - AL;
                if (L2 >= L1 && L2 >= L3)
                {
                    AH = BH;
                    AL = BL;
                }
                if (L3 >= L1 && L3 >= L2)
                {
                    AH = BH;
                }
            }
            //�������ƣ�0����
            if (curdiff)
            {
                prediff = curdiff;
            }
            presum = cursum;
        }
        if (AL > 0)
        {
            return AH;
        }
        int ret = isfirst ? AH - AL : maxValue;
        if (ret < maxValue)
        {
            return maxValue;
        }
        return ret;
    }
};
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = 0;
        int result  = INT32_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if (count > result)
            {
                result = count;
            }
            if (count < 0)
            {
                count = 0;
            }
        }return  result;
    }
};
// @lc code=end
int main()
{
    Solution so;
    vector<int> nums = { -1 };
    cout << so.maxSubArray(nums) << endl;
}