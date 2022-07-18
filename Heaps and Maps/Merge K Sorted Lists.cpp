/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* a, ListNode* b){
    ListNode* dummy = new ListNode(-1), *last = dummy;
    while(a && b){
        if(a->val < b->val){
            last->next = a;
            a = a->next;
        }
        else{
            last->next = b;
            b = b->next;
        }
        last = last->next;
    }
    if(a){
        last->next = a;
    }
    if(b){
        last->next = b;
    }
    return dummy->next;
}

ListNode* helper(vector<ListNode*> &arr, int low, int high){
    if(low > high)
        return NULL;
    if(low == high)
        return arr[low];
    int mid = low + (high-low)/2;

    auto left = helper(arr, low, mid);
    auto right = helper(arr, mid+1, high);

    return merge(left, right);
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return helper(A, 0, (int)A.size()-1);
}
