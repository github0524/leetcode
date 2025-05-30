/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] �ڶ�����
 */

//1.��ͼ�ܷ���ֻҪ���ҳ�ȫ�������Ľڵ㣬ȥ��������������ϵ��м�ڵ㼴�ɣ�ʵ����ֻ�践������������ֻͳ�Ƶ�������+1����
//2.һ��Ԫ��Ҳ�ǰڶ����У������ǳ���Ϊ1
//3.ע�ⵥ�����ж�������1.��һ��Ϊ0ʱ���˴β�Ϊ0���� 2.�ϴ���˴εķ���˻���һ����������������������� ������������������������� 2��1��1��0 �жϳ�����3����Ϊ1-1=0 ��һ�β�Ϊ0��
//�ᱻ�������ڣ���������֪����ʵ�����Բ�δ�ı䣬��ô����أ��ڼ����ʱ�򣬷��Ǽ���������0�ģ�direct�������֮ǰ�����ԵĶ������£���Ϊ=0�����ı䵥���ԣ�����������������������
#include <vector>
#include <iostream>
using namespace std;
 // @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int direct = 0;
        int end=0;
        auto begin = nums.begin();
        int tmp_direct = 0;
        if (nums.size()==1)
        {
            return 1;
        }
        //Ϊ�˷���Ԫ�ؼ����ֹԽ�磬�ӵڶ�����ʼ��
        for (begin++; begin!=nums.end(); begin++)
        {
            tmp_direct = (*begin) - (*(begin-1));
            //�ڶ�������ֻ�ʺ�һ��ʼһֱ��0��Ȼ��ı�����
            //�ٷ�д�� (curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)������ʳ��������������ǰ��diff=0��preDiffҲ�ǲ�����µģ�������ʽҲ����������
            if ((tmp_direct * direct <0) || (direct==0&&tmp_direct!=0))
            {
                end++;
            }
            if (tmp_direct > 0)
            {
                direct = 1;
            }
            if (tmp_direct < 0)
            {
                direct = -1;
            }
            //��һ�β��ܼ�������˵����=0���ı䵥���ԣ���������һ�λᵼ�����е����ı�
            //if (tmp_direct == 0)
            //{
            //    direct = 0;
            //}
        }
        return end+1;
    }
};
// @lc code=end

int main()
{
    Solution so;
    vector<int> nums = { 2,1,1,0 };
    cout << so.wiggleMaxLength(nums) << endl;
    return 0;
}
