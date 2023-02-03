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

// For GeeksforGeeks:
// struct Node {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };


// class Solution {
// public:
//     int solve(Node*root,int &k){

//         if(root==NULL)

//         return -1;

 

//         int left=solve(root->left,k);

//         if(left!=-1)
//             return left;
//         k--;
//         if(k==0) 
//             return root->data;
//         int right=solve(root->right,k);
//         if(right!=-1)
//             return right;

//   }

//     // Return the Kth smallest element in the given BST

//     int KthSmallestElement(Node *root, int K) {

//         // add code here.

//         return solve(root,K);

//     }
// };