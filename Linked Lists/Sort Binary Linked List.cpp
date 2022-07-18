/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode *one = new ListNode(-1), *zero = new ListNode(-1);
    ListNode *oneptr = one, *zeroptr = zero;

    ListNode* ptr = A;
    while(ptr){
        if(ptr->val == 0){
            zeroptr->next = ptr;
            zeroptr = zeroptr->next;
        }
        else{
            oneptr->next = ptr;
            oneptr = oneptr->next;
        }
        ptr = ptr->next;
    }
    zeroptr->next = NULL;
    oneptr->next = NULL;
    zeroptr->next = one->next;
    A = zero->next;
    delete zero;
    delete one;
    return A;
}

