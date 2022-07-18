/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* dummy = new ListNode(-1), *ptr = dummy;
    ListNode *a = A, *b = B;
    while(a && b){
        if(a->val < b->val){
            ptr->next = a;
            a = a->next;
        }
        else{
            ptr->next = b;
            b = b->next;
        }
        ptr = ptr->next;
    }
    if(a)
        ptr->next = a;
    if(b)
        ptr->next = b;
    ListNode *node = dummy->next;
    delete dummy;
    return node;
}
