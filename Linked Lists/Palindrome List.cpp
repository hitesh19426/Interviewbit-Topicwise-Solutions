/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverse(ListNode* head){
    ListNode* curr = head, *prev = NULL;
    while(curr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* middle(ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int Solution::lPalin(ListNode* head) {
    ListNode *mid = middle(head);
    ListNode *second = reverse(mid->next);
    mid->next = NULL;
    
    ListNode *sptr = second, *ptr = head;
    while(sptr){
        if(sptr->val != ptr->val)
            return false;
        sptr = sptr->next;
        ptr = ptr->next;
    }

    mid->next = reverse(second);
    return true;
}
