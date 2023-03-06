// Add two numbers represented by linked lists

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int tmp;
        cin>>tmp;
        Node *head = new Node(tmp);
        Node *tail = head;
        for(int i=0;i<n-1;i++){
            cin>>tmp;
            tail->next = new Node(tmp);
            tail = tail->next;
        }
        Solution ob;
        Node *res = ob.addTwoLists(head, head);
        while (res != NULL) {
            cout << res->data << " ";
            res = res->next;
        }
        cout << endl;
    }
    return 0;
}

class Solution{
    public:
    Node* addTwoLists(Node* first, Node* second){
        // Reverse the lists
        Node *prev = NULL, *curr = first;
        while (curr) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        first = prev;
        
        prev = NULL, curr = second;
        while (curr) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        second = prev;
        
        // Add the numbers
        int carry = 0;
        Node *head = NULL, *tail = NULL;
        while (first || second || carry) {
            int sum = carry;
            if (first) {
                sum += first->data;
                first = first->next;
            }
            if (second) {
                sum += second->data;
                second = second->next;
            }
            carry = sum / 10;
            sum %= 10;
            if (head == NULL) {
                head = new Node(sum);
                tail = head;
            } else {
                tail->next = new Node(sum);
                tail = tail->next;
            }
        }
        
        // Reverse the list
        prev = NULL, curr = head;
        while (curr) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        
        return head;
    }
};