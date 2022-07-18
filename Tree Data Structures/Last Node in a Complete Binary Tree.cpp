/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int depth(TreeNode* root){
    int count = 0;
    while(root){
        count++;
        root = root->left;   
    }
    return count;
}
int Solution::lastNode(TreeNode* root) {
    if(root == NULL)
        return -1;

    while(root->left || root->right){
        int left = depth(root->left);
        int right = depth(root->right);

        if(left > right)
            root = root->left;
        else
            root = root->right;
    }

    return root->val;
}
