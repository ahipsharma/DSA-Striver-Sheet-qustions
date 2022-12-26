class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        DFS(root, res);
        return res;
    }
    
    void DFS(TreeNode* root, vector<int>& res){
        if(!root) return;
        DFS(root->left, res);
        DFS(root->right, res);
        res.push_back(root->val);
    }
};