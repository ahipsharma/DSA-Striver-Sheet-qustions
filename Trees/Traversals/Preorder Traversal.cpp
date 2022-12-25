vector <int> preorder(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return ans;
    
}