/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool helper(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    if(root1->val != root2->val)
        return false;
    return helper(root1->left, root2->right) && helper(root1->right, root2->left);
}

int Solution::isSymmetric(TreeNode* A) {
    return helper(A->left, A->right);
}
