/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool search(TreeNode* root, int target){
    if(root == NULL)
        return false;
    if(root->val == target)
        return true;
    if(root->val > target)
        return search(root->left, target);
    return search(root->right, target);
}

bool dfs(TreeNode* node, TreeNode* root, int target){
    if(node == NULL)
        return false;
    if(target - node->val != node->val && search(root, target - node->val))
        return true;
    if(dfs(node->left, root, target))
        return true;
    return dfs(node->right, root, target);
}

int Solution::t2Sum(TreeNode* A, int B) {
    return dfs(A, A, B);
}
