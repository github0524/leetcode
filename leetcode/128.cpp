#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


//[100,4,200,1,3,2]
//�������ұ߽��ʱ��
//��ϣ���У����ҵ��ˣ�Ӧ��ɾ����ӦԪ�أ���Ȼ����������ظ�Ԫ�أ����ظ�����
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //hash
        unordered_set<int> hash;
        for (auto num:nums)
        {
            hash.insert(num);
        }
        //̰�Ĳ���
        int longest = 0;
        for (auto num:nums)
        {
            if (hash.find(num) == hash.end())
                continue;
            //����ҲҪɾ��
            hash.erase(num);
            int left = num-1;
            int right = num+1;
            //�ǵ�ɾ���ҵ���Ԫ��
            while (hash.find(left) != hash.end())
            {
                hash.erase(left);
                left--;
            }
            while (hash.find(right) != hash.end())
            {
                hash.erase(right);
                right++;
            }
            //��Ҫ+1
            longest = max(longest, right - left-2+1);
        }
        return longest;
    }
};

//��һ�ֽⷨ
//��֪������п϶��� 1 2 3 4 5 ����������Ƭ�Σ�ͬʱ�����Ƭ�ε���ʼ��1��߿϶�û�и�С������
//���������ź��˹�ϣ��֮�󣬾ͱ������飬Ȼ�����������߼�-1�ǲ���û�����ڹ�ϣ���ڣ����û�����Ǿ�һֱ�����ң���¼�°�ε��
//��������������С����߻��и�С�ģ����Ǿ������������ң��������Դ����Լ������Դ