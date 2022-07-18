/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode *dummy = new ListNode(-1), *last = dummy, *ptr = head;
    unordered_set<int> set;

    while(ptr){
        if(set.find(ptr->val) != set.end()){    // seen
            ptr = ptr->next;
        }
        else{
            set.insert(ptr->val);
            last->next = ptr;
            last = ptr;
            ptr = ptr->next;
        }
    }
    last->next = NULL;

    return dummy->next;
}
