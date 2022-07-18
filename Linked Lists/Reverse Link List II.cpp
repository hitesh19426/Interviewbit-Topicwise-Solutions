/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    int count = 1;
    ListNode* ptr = head, *m_minus_1 = NULL;
    while(count != m){
        m_minus_1 = ptr;
        ptr = ptr->next;
        count++;
    }

    ListNode* curr = ptr, *prev = NULL;
    while(count++ != n+1){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    ptr->next = curr;

    if(m_minus_1){
        m_minus_1->next = prev;
        return head;
    }
    
    return prev;
}
