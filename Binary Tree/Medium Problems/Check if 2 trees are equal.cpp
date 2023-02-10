class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *p, Node *q)
    {
        if(!p || !q) return (p == q);
        return ((p->data == q->data) && isIdentical(p->left,q->left) && isIdentical(p->right,q->right));
    }
};