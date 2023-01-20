/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        
        //Find middle element;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);//Right half has been reversed.Linking the 2 halves
        slow = slow->next;
        
        ListNode* d = head;
        while(slow != NULL){
            if(slow->val != d->val)
                return false;
            d = d->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* n = NULL;
        while(head != NULL){
            n = head->next;
            head->next = prev;
            prev = head;
            head = n;
        }
        return prev;
    }
};