#include "datatype.h"

#include <iostream>
#include <algorithm>

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
private:
    int result = INT_MIN;
public:
    int dfs(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int value = root->val;
        int leftValue = dfs(root->left);
        int rightValue = dfs(root->right);
        value = max(value, value + max(leftValue, rightValue));
        int rootValue = root->val + leftValue + rightValue;
        result = max(result, max(value, rootValue));
        return value;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return result;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    root->left = left;
    root->right = right;
    Solution so;
    
    return so.maxPathSum(root);

}