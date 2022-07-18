/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* root, int& count, int k, int &ans){
    if(root == NULL)
        return;

    inorder(root->left, count, k, ans);
    count++;
    if(count == k)
        ans = root->val;
    
    inorder(root->right, count, k, ans);
}
int Solution::kthsmallest(TreeNode* root, int k) {
    int count = 0, ans = 0;
    inorder(root, count, k, ans);
    return ans;
}
