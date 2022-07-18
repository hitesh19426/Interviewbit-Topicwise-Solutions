/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }

    if(slow != fast)
        return NULL;

    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
