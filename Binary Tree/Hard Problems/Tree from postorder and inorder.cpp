/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
// private:
//     void LeftNodes(TreeNode* root, vector<int> &left){
//         if(root == NULL)
//             return;
//         left.push_back(root->val);
//         LeftNodes(root->left, left);
//         LeftNodes(root->right, left);
//     }
//     void RightNodes(TreeNode* root, vector<int> &right){
//         if(root == NULL)
//             return;
//         right.push_back(root->val);
//         RightNodes(root->left, right);
//         RightNodes(root->right, right);
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<int> Left;
//         vector<int> Right;
        
//         TreeNode* lnode = root->left;
//         TreeNode* rnode = root->right;
        
//         if(lnode == p && rnode == q)
//             return root;
        
//         LeftNodes(lnode, Left);
//         RightNodes(rnode, Right);
        
//         for(int i = 0;i<Left.size();i++){
//             for(int j = 0;j<Left.size();j++){
//                 if(p->val == Left[i] && q->val == Left[j])
//                     return lnode;
//             }
//         }
//         for(int i = 0;i<Right.size();i++){
//             for(int j = 0;j<Right.size();j++){
//                 if(p->val == Right[i] && q->val == Right[j])
//                     return rnode;
//             }
//         }
//         return root;
        public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) return root;
        if (left != nullptr) return left;
        return right;
    }
};