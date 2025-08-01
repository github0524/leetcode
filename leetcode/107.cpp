#include <vector>
#include "datatype.h"
#include <queue>
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++)
            {
                auto tmp = que.front();
                que.pop();
                vec.push_back(tmp->val);
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            }
            ret.push_back(vec);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};