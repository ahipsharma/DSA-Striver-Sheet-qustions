class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<Node*> s;
        Node* current = root;
        
        while (current != NULL || !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }
            
            current = s.top();
            s.pop();
            
            res.push_back(current->data);
            
            current = current->right;
        }
        return res;
    }
};