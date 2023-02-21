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