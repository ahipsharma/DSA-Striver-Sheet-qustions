// For GFG:

// /*
// struct Node
// {
//     int data;
//     struct Node* left;
//     struct Node* right;

//     Node(int x){
//         data = x;
//         left = right = NULL;
//     }
// }; */

// class Solution {
//   public:
//     // Function to return the diameter of a Binary Tree.
//     int diameterOfBinaryTree(Node* root, int &maxi){
//         if(root == NULL)
//             return 0;

//         int left = diameterOfBinaryTree(root->left, maxi);
//         int right = diameterOfBinaryTree(root->right, maxi);

//         maxi = max(maxi, left+right);
//         return 1 + max(left, right);
//     }
//     int diameter(Node* root) {
//         int maxi = 0;
//         diameterOfBinaryTree(root, maxi);
//         return 1 + maxi;
//     }
// };

// For LeetCode:

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
    int diameter(TreeNode* root, int &maxi){
        if(root == NULL)
            return 0;

        int left = diameter(root->left, maxi);
        int right = diameter(root->right, maxi);

        maxi = max(maxi, left+right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        diameter(root, maxi);
        return maxi;
    }
};