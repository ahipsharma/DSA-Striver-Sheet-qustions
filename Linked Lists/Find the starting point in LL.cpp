/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head, *ptr = head;
        while(fast->next != NULL && fast != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                while(slow != ptr){
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return ptr;
            }
        }
        return NULL;
    }
};