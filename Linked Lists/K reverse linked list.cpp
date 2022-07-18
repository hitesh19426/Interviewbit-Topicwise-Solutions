/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* head, int B) {
    if(head == NULL)
        return head;

    ListNode* ptr = head;
    int count = B-1;
    while(count--){
        ptr = ptr->next;
    }
    ListNode *second = ptr->next;
    ptr->next = NULL;
    second = reverseList(second, B);

    ListNode *curr = head, *last = NULL;
    while(curr){
        ListNode* next = curr->next;
        curr->next = last;
        last = curr;
        curr = next;
    }
    // last = head, head = last node
    swap(head, last);
    last->next =  second;
    return head;
}
