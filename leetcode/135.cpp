/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] �ַ��ǹ�
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 // @lc code=start
/*
class Solution {
public:
    int candy(vector<int>& ratings) {
        //������ֱ���ϵĵ㻭��һ������ͼ����һ������0������+1���½�-1
        vector<int> candy;
        int MIN=0,rest;
        int total = 0,total2=0,total3=0;//�ȺŵĲ�ͬ�÷���Ҳ�ǲ��Եģ�������ʱ��Ⱥ��Ǽ���ʱ���Ǽ�ȥ����ʱ�������ң������������޷�����
        candy.resize(ratings.size());
        if (ratings.size() == 1) return 1;
        for (int i = 1; i < ratings.size(); i++)
        {
            rest = ratings[i] - ratings[i - 1];
            candy[i] =rest > 0 ? candy[i-1]+1 : ( candy[i-1] - 1);
            //���д��ÿ��ֻѡ1��candy��С�ģ�����MINȴ���ڵ�����
            //MIN = min(1, candy[i]);
            MIN = min(MIN, candy[i]);
            total += candy[i];
        }
        //MIN�����0���ǹ�����һ��
        return total + (1 - MIN) * ratings.size();
    }
};
*/
// @lc code=end
//����candy[i]>candy[i+1ʱ]��candy[i+1]=candy+1

//���ƴ������ұ�һ�Σ�Ȼ����������һ�Σ��������߼��ƺ�û��ʲô����
//������ĵùؼ����ڣ���һ�αȽϵ�ʱ��ȵ�������Ҵ�ĵ�Ӧ��ѡ����+1�����ǵ�һ����ߵ�ֵ����Ȼ��ȡ���������ģ�������ĿҪ����ٽ��Ķ���
//��ʼ����ȫ����ֵ��1

class Solution {
public:
    int candy(vector<int>& ratings) {
        /*������*/
        vector<int> value(ratings.size(), 1);
        int sum = 0;
        if (ratings.size() < 2) {
            return 1;
        }
        for (int i = 0; i < ratings.size() - 1; i++) {
            if (ratings[i] < ratings[i + 1]) {
                value[i + 1] = value[i] + 1;
            }
        }
        for (int i = ratings.size() - 1; i >= 1; i--) {
            if (ratings[i] < ratings[i - 1]) {
                value[i - 1] = value[i - 1] > value[i] + 1 ? value[i - 1] : value[i] + 1;
            }
        }
        for (auto k : value)
        {
            sum += k;
        }
        return sum;
    }
};

int main() {
    Solution so;
    vector<int> nums = { 1,3,4,5,2 };
    cout << so.candy(nums) << endl;
    return 0;
}
