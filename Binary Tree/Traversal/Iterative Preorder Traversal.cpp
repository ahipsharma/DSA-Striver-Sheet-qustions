vector <int> preorder(Node* root){
  stack<Node*> st;
  vector <int> res;
  st.push(root);
  while(!st.empty()){
      Node* node = st.top();
      res.push_back(node->data);
      st.pop();
      if(node->right) st.push(node->right);
      if(node->left) st.push(node->left);
  }
  return res;
}