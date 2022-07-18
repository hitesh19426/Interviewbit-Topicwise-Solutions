/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode *head){
    ListNode* curr = head, *prev = NULL;
    while(curr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* removehead(ListNode* head){
    ListNode* next = head->next;
    delete head;
    return next;
}

ListNode* Solution::solve(ListNode* head) {
    ListNode *evenhead = new ListNode(-1), *even = evenhead;
    ListNode *oddhead = new ListNode(-1), *odd = oddhead;
    ListNode* curr = head;
    bool isEven = false;
    while(curr){
        if(isEven){
            even->next = curr;
            even = even->next;
        }
        else{
            odd->next = curr;
            odd = odd->next;
        }
        curr = curr->next;
        isEven = !isEven;
    }
    odd->next = NULL, even->next = NULL;
    oddhead = removehead(oddhead), evenhead = removehead(evenhead);

    evenhead = reverse(evenhead);

    odd = oddhead, even = evenhead;
    ListNode* dummy = new ListNode(-1), *ptr = dummy;
    while(even){
        ptr->next = odd;
        odd = odd->next;

        ptr->next->next = even;
        even = even->next;
        
        ptr = ptr->next->next;
    }
    if(odd){
        ptr->next = odd;
    }

    head = removehead(dummy);
    return head;
}
