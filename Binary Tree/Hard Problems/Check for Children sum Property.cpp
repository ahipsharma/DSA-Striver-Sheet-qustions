class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool isSumProperty(Node* root) {
        if (root == NULL) {
            // An empty tree satisfies the sum property
            return true;
        }
    
        if (root->left == NULL && root->right == NULL) {
            // A leaf node satisfies the sum property
            return true;
        }
    
        int sum = 0;
        if (root->left != NULL) {
            sum += root->left->data;
            if (!isSumProperty(root->left)) {
                // If the left child doesn't satisfy the sum property, return false
                return false;
            }
        }
    
        if (root->right != NULL) {
            sum += root->right->data;
            if (!isSumProperty(root->right)) {
                // If the right child doesn't satisfy the sum property, return false
                return false;
            }
        }
    
        // Check if the current node satisfies the sum property
        return root->data == sum;
    }
};