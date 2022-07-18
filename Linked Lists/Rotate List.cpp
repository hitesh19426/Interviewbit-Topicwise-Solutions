/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

ListNode* Solution::rotateRight(ListNode* head, int B) {
    int len = length(head);
    B %= len;

    if(B == 0)
        return head;

    int count = len-B-1;
    ListNode* ptr = head;
    while(count--){
        ptr = ptr->next;
    }

    ListNode *second = ptr->next;
    ptr->next = NULL, ptr = second;
    while(ptr->next){
        ptr = ptr->next;
    }
    // ptr = 5, second = 4, head = 1
    ptr->next = head;
    return second;

}
