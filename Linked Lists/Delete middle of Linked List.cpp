#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};


class Solution {
private:
ListNode* getMiddle(ListNode* head){
    ListNode* slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* ptr = new ListNode();
        if(head == NULL || head->next == NULL)
            return NULL;
        ptr = getMiddle(head);
        ListNode* prev = head;
        while(prev->next != ptr){
            prev = prev->next;
        }
        ListNode* nextNode = ptr->next;
        prev->next = nextNode;
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* ptr = s.deleteMiddle(head);
    while(ptr != NULL){
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    return 0;
}