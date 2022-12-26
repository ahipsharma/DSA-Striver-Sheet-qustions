class Solution {
public:
    vector<int> inorderTraversal(TreeNode* curr) {
        vector<int> ans;
        if(curr == nullptr)
            return ans;
        stack<TreeNode*> s;
        s.push(curr);
        while (true) {
            if (curr != NULL) {
              s.push(curr);
              curr = curr -> left;
            } 
            else {
              if (s.empty()) break;
              curr = s.top();
              ans.push_back(curr -> val);
              s.pop();
              curr = curr -> right;
            }
        }
        return ans;
    }
};