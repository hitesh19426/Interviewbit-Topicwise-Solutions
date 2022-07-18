/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    ListNode* third = head->next->next;
    head->next->next = NULL;
    third = swapPairs(third);

    ListNode* curr = head, *last = NULL;
    while(curr){
        ListNode* next = curr->next;
        curr->next = last;
        last = curr;
        curr = next;
    }
    swap(head, last);

    last->next = third;
    return head;
}
