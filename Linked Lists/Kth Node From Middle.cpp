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
        head = head->next;
        count++;
    }
    return count;
}

int Solution::solve(ListNode* A, int B) {
    int len = length(A);
    int index = (len/2)+1-B;
    if(index <= 0){
        return -1;
    }

    index--;
    ListNode* ptr = A;
    while(index--){
        ptr = ptr->next;
    }
    return ptr->val;

}
