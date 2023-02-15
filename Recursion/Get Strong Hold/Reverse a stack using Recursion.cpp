class Solution{
public:
    void insertAtBottom(stack<int>& s, int elem){
        if(s.empty()){
            s.push(elem);
            return;
        }
        int temp = s.top();
        s.pop();
        insertAtBottom(s, elem);
        s.push(temp);
    }

    void Reverse(stack<int>& s){
        if(!s.empty()){
            int temp = s.top();
            s.pop();
            Reverse(s);
            insertAtBottom(s, temp);
        }
    }
};