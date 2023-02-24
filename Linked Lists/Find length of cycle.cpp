int countNodesinLoop(struct Node *head){
    Node* slow = head, *fast = head;
    int c = 1;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            break;
    }
    if(fast->next == NULL || fast->next->next == NULL)
        return 0;
    fast = fast->next;
    while(slow != fast){
        fast = fast->next;
        c++;
    }
    return c;
}