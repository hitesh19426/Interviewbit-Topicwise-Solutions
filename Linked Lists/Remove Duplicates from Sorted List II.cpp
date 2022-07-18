/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    ListNode* dummy = new ListNode(-1), *last = dummy, *ptr = head;
    int toignore = ptr->val - 1;
    while(ptr && ptr->next){
        if(ptr->val == ptr->next->val){
            toignore = ptr->next->val;
        }
        else{
            if(ptr->val != toignore){
                last->next = ptr;
                last = ptr;
            }
        }
        ptr = ptr->next;
    }
    if(ptr &&  ptr->val != toignore){
        last->next = ptr;
        last = last->next;
    }

    last->next = NULL;
    return dummy->next;
}
