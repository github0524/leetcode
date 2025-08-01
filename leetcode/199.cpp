#include <vector>
#include "datatype.h"
#include <queue>
#include <algorithm>
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr)return ret;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                auto tmp = que.front();
                que.pop();
                if (i == (size - 1)) ret.push_back(tmp->val);
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            }
        }
        return ret;
    }
};
// 方法1：使用特殊值 (INT_MIN) 标记空节点
TreeNode* buildTreeWithSpecialValue(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == INT_MIN) return nullptr;

    auto root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    for (int i = 1; i < nodes.size(); ) {
        TreeNode* parent = q.front();
        q.pop();

        // 处理左子节点
        if (i < nodes.size()) {
            if (nodes[i] != INT_MIN) {
                parent->left = new TreeNode(nodes[i]);
                q.push(parent->left);
            }
            i++;  // 移动索引
        }

        // 处理右子节点
        if (i < nodes.size()) {
            if (nodes[i] != INT_MIN) {
                parent->right = new TreeNode(nodes[i]);
                q.push(parent->right);
            }
            i++;  // 移动索引
        }
    }
    return root;
}

// 辅助函数：层序遍历打印树结构
void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                cout << "null ";
                continue;
            }
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
        cout << endl;
    }
}

int main()
{
    TreeNode* root;
    vector<int> vec{ 1,2,3,INT_MIN,5,INT_MIN,4 };

    root = buildTreeWithSpecialValue(vec);
    printTree(root);
    Solution so;
    so.rightSideView(root);
    return 0;
}