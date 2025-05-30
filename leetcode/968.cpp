#include "datatype.h"
#include <iostream>

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
/*
0 �и���
1 �о�ͷ
2 �޸���
*/
class Solution {
private:
    int result=0;
    int LRD(TreeNode* ro) {
        if (ro == nullptr) return 0;
        int left = LRD(ro->left);
        int right = LRD(ro->right);
        if (left == 2 || right == 2)
        {
            result++;
            return 1;
        }
        if (left == 1 || right == 1)
        {
            return 0;
        }
        if (left == 0 && right == 0)
        {
            return 2;
        }
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        if (LRD(root)==2)
        {
            result++;
        }
        return result;
    }
};

int main()
{
    Solution so;
    TreeNode* root = new TreeNode(0); // ���ڵ�
    root->left = new TreeNode(0);      // ���ӽڵ�
    root->right = nullptr;              // ���ӽڵ�Ϊ null
    root->left->left = new TreeNode(0); // ���ӽڵ�����ӽڵ�
    root->left->right = new TreeNode(0); // ���ӽڵ�����ӽڵ�

    cout << so.minCameraCover(root) << endl;
    return 0;
}