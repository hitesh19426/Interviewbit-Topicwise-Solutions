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

int helper(TreeNode* root, int target){
    if(root == NULL)
        return false;
    if(isleaf(root)){
        return root->val == target;
    }

    return helper(root->left, target - root->val) || helper(root->right, target - root->val);
}

int Solution::hasPathSum(TreeNode* root, int target) {
    return helper(root, target);
}
