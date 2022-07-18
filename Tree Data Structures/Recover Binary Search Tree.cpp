/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void recover(TreeNode* root, TreeNode* &beforefirst, TreeNode* &first, TreeNode* &second, TreeNode* &prev){
    if(root == NULL)
        return;

    recover(root->left, beforefirst, first, second, prev);

    if(prev && root->val < prev->val){
        if(first == NULL)
            first = root, beforefirst = prev;
        else
            second = root;
    }
    prev = root;

    recover(root->right, beforefirst, first, second, prev);
}

vector<int> Solution::recoverTree(TreeNode* root) {
    if(root == NULL)
        return {};

    TreeNode *beforefirst = NULL, *first = NULL, *second = NULL, *prev = NULL;
    recover(root, beforefirst, first, second, prev);

    if(second == NULL){
        return {first->val, beforefirst->val};
    }
    else{
        return {second->val, beforefirst->val};
    }

    return {};
}
