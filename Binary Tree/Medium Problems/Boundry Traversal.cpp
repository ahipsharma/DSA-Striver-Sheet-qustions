class Solution{
    public:
    void addLeftBoundary(Node* root, vector<int>& res) {
        if (!root || (!root->left && !root->right)) {
            return;
        }
        res.push_back(root->data);
        if (root->left) {
            addLeftBoundary(root->left, res);
        } else {
            addLeftBoundary(root->right, res);
        }
    }
    
    void addRightBoundary(Node* root, vector<int>& res) {
        if (!root || (!root->left && !root->right)) {
            return;
        }
        if (root->right) {
            addRightBoundary(root->right, res);
        } else {
            addRightBoundary(root->left, res);
        }
        res.push_back(root->data);
    }
    
    void addLeaves(Node* root, vector<int>& res) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }
    
    vector<int> boundary(Node* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        res.push_back(root->data);
        addLeftBoundary(root->left, res);
        addLeaves(root, res);
        addRightBoundary(root->right, res);
        return res;
    }
};