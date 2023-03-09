vector<int> postOrder(Node* root){
    vector<int> res;
    if (root == NULL) {
        return res;
    }

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left) {
            s1.push(current->left);
        }

        if (current->right) {
            s1.push(current->right);
        }
    }

    while (!s2.empty()) {
        Node* current = s2.top();
        s2.pop();
        res.push_back(current->data);
    }
    return res;
}