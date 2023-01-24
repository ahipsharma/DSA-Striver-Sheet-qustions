class Solution {
public:
    void parenthesis(int open, int close, string op, vector<string> &res){
        if(open == 0 && close == 0){
            res.push_back(op);
            return;
        }
        if(open != 0){
            string s1 = op;
            s1.push_back('(');
            parenthesis(open - 1, close, s1, res);
        }
        if(open < close){
            string op1 = op;
            op1.push_back(')');
            parenthesis(open, close - 1, op1, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open = n, close = n;
        string op = "";
        parenthesis(open, close, op, res);
        return res;
    }
};