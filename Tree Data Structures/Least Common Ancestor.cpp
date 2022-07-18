/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int search(TreeNode* root, int p){
    if(root == NULL)
        return false;
    if(root->val == p)
        return true;
    return search(root->left, p) || search(root->right, p);
}

int helper(TreeNode* root, int p, int q){
    if(root == NULL)
        return -1;
    if(root->val == p || root->val == q)
        return root->val;
    int left = helper(root->left, p, q);
    int right = helper(root->right, p, q);
    if(left == -1 && right == -1)
        return -1;
    if(left == -1 || right == -1)
        return (left == -1 ? right : left);
    return root->val;
}

int Solution::lca(TreeNode* root, int p, int q) {
    bool pexist = search(root, p);
    bool qexist = search(root, q);

    if(pexist == false || qexist == false)
        return -1;
    return helper(root, p, q);
}
