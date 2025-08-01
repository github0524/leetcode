#include <vector>
#include "datatype.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        vector<TreeNode*> tmp;
        tmp.push_back(root);
        //本层不为空
        while (!tmp.empty())
        {
            //1.将本层非空节点加入结果、获取全部非空子节点，保存到下一轮
            vector<int> subans;
            vector<TreeNode*> newNode;
            for (auto& element:tmp)
            {
                subans.push_back(element->val);
                if (element->left)
                {
                    newNode.push_back(element->left);
                }
                if (element->right)
                {
                    newNode.push_back(element->right);
                }
            }
            ans.push_back(subans);
            tmp = newNode;
            
        }
        return ans;
    }
};