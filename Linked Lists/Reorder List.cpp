/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* middle(ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverse(ListNode* head){
    ListNode* curr = head, *prev = NULL;
    while(curr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* Solution::reorderList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    ListNode *mid = middle(head), *second = mid->next;
    mid->next = NULL;
    second = reverse(second);

    ListNode *dummy = new ListNode(-1), *ptr = dummy;
    while(second){
        ptr->next = head;
        head = head->next;
        ptr = ptr->next;

        ptr->next = second;
        second = second->next;
        ptr = ptr->next;
    }
    if(head){
        ptr->next = head;
    }

    return dummy->next;
}
