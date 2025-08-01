#include "datatype.h"


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
    bool duicheng(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr) return true;
        if ((left == nullptr && right != nullptr) || (right == nullptr && left != nullptr)) return false;
        if (left->val != right->val) return false;
        return duicheng(left->left, right->right) && duicheng(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)return true;
        return duicheng(root->left, root->right);
    }
};

int main()
{

}