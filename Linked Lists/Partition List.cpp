/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *less = new ListNode(-1), *greater = new ListNode(-1);
    ListNode *lptr = less, *gptr = greater;

    ListNode *ptr = A;
    while(ptr){
        if(ptr->val < B){
            lptr->next = ptr;
            lptr = lptr->next;
        }
        else{
            gptr->next = ptr;
            gptr = gptr->next;
        }
        ptr = ptr->next;
    }
    lptr->next = NULL, gptr->next = NULL;
    lptr->next = greater->next;
    A = less->next;

    delete less, greater;
    return A;
}
