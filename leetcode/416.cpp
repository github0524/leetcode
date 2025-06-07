
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 2 3 3  4 5
// ������� �� ֻ��������  �� �ӷ�
//���� ������һ��������һ��ĺ�
// ���������Ŀ϶�����
//Ҳ������ ��������+ĳ�������ܲ��ܵ�������һ�루�������һ��С�ڰ���-��������

//�ܽ����0/1��������������û����������ܵ�value�ܹ��ﵽ sum/2
//Ϊʲôÿһ����Ҫ��������ֵ����Ϊ01�������Ȿ����ָ�ģ�һ��������������һ����ϳ��ļ�ֵ���
//����������ͼ�ֵ����ˣ����ڷ�����Ŀ��������ϣ�һ���Ǵ�����������ϵģ���֮�Ͳ�����


//����Ƶ
//ÿһ�е���Ʒ���ǰ���˳���ĵģ���ȫ��ɢ��ֻ���Ƿ���Ͳ����������Ƿ��ܶ�Ӧ��ÿһ�������ֵ��ֻ��true��false

//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        int sum = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            sum += nums[i];
//        }
//        //����
//        if (sum%2==1)
//        {
//            return false;
//        }
//        vector<vector<bool>> dp(nums.size(), vector<bool>(sum/2 + 1, false));
//        if (nums[0]<= sum/2)
//        {
//            dp[0][nums[0]] = true;
//        }
//        for (int i = 1; i < nums.size(); i++)
//        {
//            //������һ��������һ��
//            if (nums[i]>sum/2)
//            {
//                return false;
//            }
//            for (int j = 0; j < nums[i]; j++) {
//                dp[i][j] == dp[i - 1][j];
//            }
//            //�������j<nums[i]
//            for (int j = nums[i]; j <=sum/2; j++)
//            {
//                //��ѡ
//                if (dp[i-1][j]==true)
//                {
//                    dp[i][j] = true;
//                    continue;
//                }
//                //ѡ
//                if (nums[i]==sum/2)
//                {
//                    return true;
//                }
//                dp[i][j] = dp[i - 1][j - nums[i]];
//            }
//        }
//        return dp[nums.size() - 1][sum / 2];
//    }
//};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        if (n < 2)
            return false;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        int max = *max_element(nums.begin(), nums.end());
        int target = sum / 2;
        if (max>target)
            return false;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

//dp��ӡ
/*for (int i = 0; i < dp[0].size(); i++)
{
    cout << "\t" << i;
}
cout << endl;
for (int i = 0; i < dp.size(); i++)
{
    cout << nums[i] << "\t";

    for (int j = 0; j < dp[0].size(); j++)
        cout << dp[i][j] << "\t";
    cout << endl;
}*/
//ʹ�� accumulate �� max_element���������࣬������⡣
//��ǰ��� maxNum > target���߼���������������ʵ�������и��졣
//��ȷ���� $n < 2$ �ı߽���������ϱ�̹淶��
//�ٷ�д�ĸ��ã��Ҷ���ѡ�벻ѡ�Ĺ��ɸ�����
//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        int n = nums.size();
//        if (n < 2) {
//            return false;
//        }
//        int sum = accumulate(nums.begin(), nums.end(), 0);
//        int maxNum = *max_element(nums.begin(), nums.end());
//        if (sum & 1) {
//            return false;
//        }
//        int target = sum / 2;
//        if (maxNum > target) {
//            return false;
//        }
//        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
//        for (int i = 0; i < n; i++) {
//            dp[i][0] = true;
//        }
//        dp[0][nums[0]] = true;
//        for (int i = 1; i < n; i++) {
//            int num = nums[i];
//            for (int j = 1; j <= target; j++) {
//                if (j >= num) {
//                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
//                }
//                else {
//                    dp[i][j] = dp[i - 1][j];
//                }
//            }
//        }
//        return dp[n - 1][target];
//    }
//};

int main()
{
    Solution so;
    vector<int> nums{ 1,5,11,5 };
    cout << so.canPartition(nums) << endl;
    return 0;

}