/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isleaf(TreeNode* root){
    return (!root->left && !root->right);
}
void dfs(TreeNode* root, int sum, int &ans, int mod){
    if(root == NULL)
        return;
    if(isleaf(root)){
        ans = (ans + 10*sum + root->val)%mod;
        return;
    }

    dfs(root->left, (10*sum + root->val)%mod, ans, mod);
    dfs(root->right, (10*sum + root->val)%mod, ans, mod);
}
int Solution::sumNumbers(TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans, 1003);
    return ans;
}
