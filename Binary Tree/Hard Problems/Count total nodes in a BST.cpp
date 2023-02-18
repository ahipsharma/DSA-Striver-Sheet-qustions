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
    void inorder(TreeNode* root, int &c){
        if(root == NULL)
            return;
        c++;
        inorder(root->left, c);
        inorder(root->right, c);
        
    }
    int countNodes(TreeNode* root) {
        int c = 0;
        inorder(root, c);
        return c;
    }
};