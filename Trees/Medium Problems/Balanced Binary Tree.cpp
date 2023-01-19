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
    bool isBalanced(TreeNode* root) {
        return balanced(root) != -1;
    }xw

    int balanced(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left = balanced(root->left);
        int right = balanced(root->right);

        if(abs(left - right) > 1)
            return -1;
        if(left == -1 || right == -1)
            return -1;
        else
            return 1 + max(left, right);
    }
};