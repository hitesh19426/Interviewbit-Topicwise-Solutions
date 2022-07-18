/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* insert(ListNode* head, ListNode *node){
    ListNode* dummy = new ListNode(-1), *ptr = head, *temp = dummy;
    while(ptr && ptr->val < node->val){
        temp->next = ptr;
        temp = temp->next;
        ptr = ptr->next;
    }
    node->next = ptr;
    temp->next = node;
    ListNode *toreturn = dummy->next;
    delete dummy;
    return toreturn;
}

ListNode* Solution::insertionSortList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* ptr = head->next;
    head->next = NULL;
    while(ptr){
        ListNode* next = ptr->next;
        ptr->next = NULL;
        head = insert(head, ptr);
        ptr = next;
    }
    return head;
}
