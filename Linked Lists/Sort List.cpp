/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* middle(ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* head1, ListNode *head2){
    if(head1 == nullptr || head2 == nullptr)
        return (head1 ? head1 : head2);
    
    ListNode* dummy = new ListNode(-1), *nptr = dummy;
    while(head1 && head2){
        if(head1->val < head2->val){
            nptr->next = head1;
            head1 = head1->next;
        }
        else{
            nptr->next = head2;
            head2 = head2->next;
        }
        nptr = nptr->next;
    }
    if(head1)
        nptr->next = head1;
    if(head2)
        nptr->next = head2;
    return dummy->next;
}

ListNode* mergeSort(ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *mid = middle(head);
    ListNode *next = mid->next;
    mid->next = NULL;
    head = mergeSort(head);
    next = mergeSort(next);
    return merge(head, next);
}

ListNode* Solution::sortList(ListNode* A) {
    return mergeSort(A);
}
