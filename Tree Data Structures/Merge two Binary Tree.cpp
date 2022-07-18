/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL && root2 == NULL)
        return NULL;
    if(root1 == NULL || root2 == NULL)
        return (root1 ? root1 : root2);
    root1->val += root2->val;
    root1->left = solve(root1->left, root2->left);
    root1->right = solve(root1->right, root2->right);
    return root1;
}
