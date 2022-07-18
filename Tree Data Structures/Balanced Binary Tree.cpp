/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
pair<bool, int> helper(TreeNode* root){
    if(root == NULL){
        return {true, 0};
    }

    auto left = helper(root->left);
    auto right = helper(root->right);

    int height = 1 + max(left.second, right.second);

    if(left.first == false || right.first == false)
        return {false, height};
    return {abs(left.second - right.second) <= 1, height};
}
int Solution::isBalanced(TreeNode* root) {
    return helper(root).first;
}
