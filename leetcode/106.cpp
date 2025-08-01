#include "datatype.h"
#include <vector>

using namespace std;

//�����������������й��������
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

        //���������������һ��Ԫ�أ����ǵ�ǰ���м�ڵ�
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        //ֻ��һ���ڵ�����
        if (postorder.size() == 1) return root;

        // �ҵ�����������и��
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        //�и���������
        //����ҿ�����
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        //���ұ�����
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        //postorder ����ĩβԪ��
        postorder.resize(postorder.size() - 1);

        //�и��������
        vector<int> leftPostInorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostInorder(postorder.begin() + leftInorder.size() , postorder.end());

        //�����ӽڵ��ָ��
        root->left = buildTree(leftInorder, leftPostInorder);
        root->right = buildTree(rightInorder, rightPostInorder);

        return root;
    }
};