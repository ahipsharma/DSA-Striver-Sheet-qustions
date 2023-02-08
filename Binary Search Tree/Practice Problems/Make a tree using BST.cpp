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
    // Imp to pass root vai reference!!!
    void insert(TreeNode* &root, int x){
        if(root == NULL){
            // If root equals NULL, create a new node.
            root = new TreeNode(x);
            return;
        }
        else if(root->val > x)
            insert(root->left, x);
        else
            insert(root->right, x);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* temp = root;
        for(int i=1; i<n; i++){
            insert(temp, preorder[i]);
        }
        return root;
    }
};