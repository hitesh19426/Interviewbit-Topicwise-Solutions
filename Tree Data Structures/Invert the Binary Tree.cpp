/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* root) {
    if(root == NULL)
        return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
