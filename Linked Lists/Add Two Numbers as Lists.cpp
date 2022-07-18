/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* dummy = new ListNode(-1), *ptr = dummy;
    int carry = 0;
    while(A || B){
        int x = A ? A->val : 0;
        int y = B ? B->val : 0;

        if(A){
            A->val = (x+y+carry)%10;
            ptr->next = A;
        }
        else{
            B->val = (x+y+carry)%10;
            ptr->next = B;
        }
        carry = (x+y+carry)/10;
        ptr = ptr->next;

        A = A ? A->next : NULL;
        B = B ? B->next : NULL;
    }
    if(carry){
        ptr->next = new ListNode(carry);
    }
    return dummy->next;
}
