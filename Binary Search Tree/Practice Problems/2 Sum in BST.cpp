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
    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    bool findNum(vector<int> &v, int sum){
        int i = 0, j = v.size()-1;
        while(i<j){
            if(v[i] + v[j] > sum)
                j--;
            else if(v[i] + v[j] < sum)
                i++;
            else{
                return true;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int x) {
        vector<int> v;
        inorder(root, v);
        return findNum(v, x);
    }
};