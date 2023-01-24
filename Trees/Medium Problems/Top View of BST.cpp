class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){
        queue<pair<Node*, int>> q;
        map<int, int> m;
        vector<int> res;
        
        q.push({root, 0});
        while(!q.empty()){
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(m.find(level) == m.end()) m[level] = node->data;
            if(node->left)  q.push({node->left, level - 1});
            if(node->right) q.push({node->right, level + 1});
        }
        
        for(auto it:m)
            res.push_back(it.second);
        
        return res;
    }

};