/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* ahead = A;
    while(B-- && ahead){
        ahead = ahead->next;
    }
    if(!ahead){
        return A->next;
    }

    ListNode* prev = NULL, *curr = A;
    while(ahead){
        ahead = ahead->next;
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    return A;
}
