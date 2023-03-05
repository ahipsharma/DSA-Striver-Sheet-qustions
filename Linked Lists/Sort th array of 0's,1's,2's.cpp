/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
private:
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* l1, Node*l2){
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        Node* ans = new Node(-1);
        Node* temp = ans;
        while(l1 != NULL && l2!=NULL){
            if(l1->data < l2->data){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if(l1!=NULL){
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        if(l2!=NULL){
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
        ans = ans->next;
        return ans;
    }
public:
    Node* segregate(Node* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        // Find mid element of Linked List
        Node*mid = findMid(head);
        
        // Pointing the 
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        
        left = segregate(left);
        right = segregate(right);
        
        // Merge 2 halves.
        Node* result = merge(left, right);
        return result;
    }
};