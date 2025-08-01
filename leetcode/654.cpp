#include "datatype.h"
#include <vector>

using namespace std;

//leetcode 654
// 代码存在一个问题：
// 在 constructMaximumBinaryTree 方法中，右子树递归时，vec1 包含了当前最大值节点本身，应该是 nums.begin() + index + 1 到 nums.end()
// 否则会导致死循环或重复节点。
// 修正如下：
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
        vector<int> vec1(nums.begin() + index + 1, nums.end()); // 修正此处
        root->right = constructMaximumBinaryTree(vec1);

        return root;
    }
};