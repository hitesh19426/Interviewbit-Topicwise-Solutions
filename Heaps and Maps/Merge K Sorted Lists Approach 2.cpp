/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct comparator{
    bool operator()(const ListNode* a, const ListNode* b){
        return a->val > b->val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    priority_queue<ListNode*, vector<ListNode*>, comparator> minheap;

    for(auto head:A){
        minheap.push(head);
    }

    ListNode* dummy = new ListNode(-1), *last = dummy;
    while(not minheap.empty()){
        auto top = minheap.top();
        minheap.pop();

        last->next = top;
        last = last->next;
        if(top->next)
            minheap.push(top->next);
    }

    return dummy->next;
}