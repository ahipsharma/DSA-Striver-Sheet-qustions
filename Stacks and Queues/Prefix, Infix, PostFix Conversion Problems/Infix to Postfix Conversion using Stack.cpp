class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        }
        else if (op == '*' || op == '/') {
            return 2;
        }
        else if (op == '^') {
            return 3;
        }
        return 0;
    }
    
    string infixToPostfix(string infix) {
        stack<char> s;
        string postfix;
    
        for (char c : infix) {
            if (isalnum(c)) {
                postfix += c;
            }
            else if (c == '(') {
                s.push(c);
            }
            else if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                s.pop(); // remove '('
            }
            else {
                while (!s.empty() && precedence(c) <= precedence(s.top())) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
    
        while (!s.empty()) {
            postfix += s.top();
            s.pop();
        }
    
        return postfix;
    }
};