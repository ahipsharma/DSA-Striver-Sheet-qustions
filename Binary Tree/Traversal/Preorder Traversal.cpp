void preOrderTrav(Node* curr, vector<int> &res) {
    if (curr == NULL)
        return;
    
    res.push_back(curr->data);
    preOrderTrav(curr->left, res);
    preOrderTrav(curr->right, res);
}

vector<int> preorder(Node* root){
    vector <int> res;
    preOrderTrav(root, res);
    return res;
}