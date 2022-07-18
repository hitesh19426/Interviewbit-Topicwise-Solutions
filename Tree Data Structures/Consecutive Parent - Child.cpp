/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode* root, TreeNode* parent, int &count){
    if(root == NULL)
        return;
    
    if(parent && abs(root->val - parent->val) == 1){
        count++;
    }

    helper(root->left, root, count);
    helper(root->right, root, count);
}
int Solution::consecutiveNodes(TreeNode* root) {
    if(root == NULL)
        return 0;
    
    int count = 0;
    helper(root, NULL, count);
    return count;
}
