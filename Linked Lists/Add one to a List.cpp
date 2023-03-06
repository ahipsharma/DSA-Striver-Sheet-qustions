// Add one to a list

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
        Node *res = ob.addOne(head);
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
    Node* addOne(Node* head) {
        // Reverse the list
        Node *prev = NULL, *curr = head;
        while (curr) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    
        // Add 1 to the number
        int carry = 1;
        curr = head;
        while (curr && carry) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            curr = curr->next;
        }
    
        // Reverse the list again
        prev = NULL, curr = head;
        while (curr) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    
        // Add an extra node if there is still a carry
        if (carry) {
            Node *newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};