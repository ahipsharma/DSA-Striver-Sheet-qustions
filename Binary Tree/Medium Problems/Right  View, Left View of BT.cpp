

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root){
    
   // Your code here
   queue<pair<Node*, int>> q;
   map<int, int> m;
   vector<int> res;
   if(root == NULL)
    return res;
   q.push({root, 0});
   
   while(!q.empty()){
       auto it = q.front();
       Node* node = it.first;
       int line = it.second;
       q.pop();
       
       if(m.find(line) == m.end()) m[line] = node->data;
       
       if(node->left) q.push({node->left, line+1});
       if(node->right) q.push({node->right, line+1});
       
   }
   for(auto it:m){
       res.push_back(it.second);
   }
   return res;
}