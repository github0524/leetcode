#include "datatype.h"
#include <vector>

using namespace std;

//从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return nullptr;

        //后续遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        //只有一个节点的情况
        if (postorder.size() == 1) return root;

        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        //切割中序数组
        //左闭右开区间
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        //左开右闭区间
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        //postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        //切割后序数组
        vector<int> leftPostInorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostInorder(postorder.begin() + leftInorder.size() , postorder.end());

        //左右子节点的指针
        root->left = buildTree(leftInorder, leftPostInorder);
        root->right = buildTree(rightInorder, rightPostInorder);

        return root;
    }
};