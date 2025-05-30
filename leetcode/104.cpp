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
#include<iostream>
#include "datatype.h"
#include <forward_list>

using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int max = left > right ? left : right;
        return max+1;
    }
};

int main()
{
    forward_list<int> fl;
    auto  ret = [](int a, int b) { return a + b; };
    cout << ret(1, 2) << endl;
    return 0;
}

