class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
    int dfs(Node* node, int& maxSum) {
        if(!node) return 0;
        int leftSum = max(dfs(node->left, maxSum), 0);
        int rightSum = max(dfs(node->right, maxSum), 0);
        maxSum = max(maxSum, leftSum + rightSum + node->data);
        return max(leftSum, rightSum) + node->data;
    }
};