/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head){
    ListNode* curr = head, *last = NULL;
    while(curr){
        ListNode* next = curr->next;
        curr->next = last;
        last = curr;
        curr = next;
    }
    swap(last, head);
    return head;
}

ListNode* helper(ListNode* head, int B, bool toreverse = true){
    if(head == NULL || head->next == NULL)
        return head;
    
    int count = B-1;
    ListNode* ptr = head;
    while(count-- && ptr){
        ptr = ptr->next;
    }
    if(!ptr){
        return (toreverse ? reverse(head) : head);
    }

    ListNode* second = ptr->next;
    ptr->next = NULL;

    ListNode* curr = head, *last = NULL;
    while(curr){
        ListNode *next = curr->next;
        if(toreverse){
            curr->next = last;
        }
        last = curr;
        curr = next;
    }
    if(toreverse)
        swap(last, head);
    
    last->next = helper(second, B, !toreverse);
    return head;
}

ListNode* Solution::solve(ListNode* A, int B) {
    return helper(A, B);
}
