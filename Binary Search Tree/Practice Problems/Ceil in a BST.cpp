void inorder(Node* root, vector<int> &res){
    if(root == NULL)
        return;
    
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    vector<int> res;
    inorder(root, res);
    int x;
    for(int i:res){
        if(i>=input)
            return i;
    }
    return -1;
}