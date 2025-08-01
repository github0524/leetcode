#include "datatype.h"
#include <vector>

using namespace std;

//leetcode 654
// �������һ�����⣺
// �� constructMaximumBinaryTree �����У��������ݹ�ʱ��vec1 �����˵�ǰ���ֵ�ڵ㱾��Ӧ���� nums.begin() + index + 1 �� nums.end()
// ����ᵼ����ѭ�����ظ��ڵ㡣
// �������£�
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }

        int index = 0;
        int maxvalue = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxvalue)
            {
                index = i;
                maxvalue = nums[i];
            }
        }

        TreeNode* root = new TreeNode(nums[index]);
        vector<int> vec(nums.begin(), nums.begin() + index);
        root->left = constructMaximumBinaryTree(vec);
        vector<int> vec1(nums.begin() + index + 1, nums.end()); // �����˴�
        root->right = constructMaximumBinaryTree(vec1);

        return root;
    }
};