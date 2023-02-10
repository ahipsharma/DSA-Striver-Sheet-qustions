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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> arr(n);
            for(int i = 0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                int idx = (flag) ? i : (n-i-1);
                arr[idx] = node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag = !flag;
            res.push_back(arr);
        }
        return res;
    }
};