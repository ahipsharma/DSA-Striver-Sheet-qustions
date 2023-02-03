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
private:
    void bfs(TreeNode*root, vector<long> &ans){
        if(root == NULL)
            return;
        bfs(root->left, ans);
        ans.push_back(root->val);
        bfs(root->right, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<long> ans;
        bfs(root, ans);
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};