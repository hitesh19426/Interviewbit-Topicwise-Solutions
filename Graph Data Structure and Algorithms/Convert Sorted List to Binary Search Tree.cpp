/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
pair<ListNode*,ListNode*> middle(ListNode* head){
    if(head == NULL)
        return {NULL, NULL};
    
    ListNode* slow = head, *fast = head->next, *prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return {slow, prev};
}

TreeNode* helper(ListNode* head){
    if(head == NULL)
        return NULL;

    auto mid = middle(head);
    ListNode* curr = mid.first, *prev = mid.second;
    if(prev)
        prev->next = NULL;

    TreeNode* node = new TreeNode(curr->val);
    node->left = helper((prev ? head : NULL));
    node->right = helper(curr->next);

    return node;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return helper(A);
}
