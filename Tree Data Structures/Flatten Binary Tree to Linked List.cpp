/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(root == NULL)
        return root;

    TreeNode* ptr = root;
    while(ptr){
        if(ptr->left)
            swap(ptr->left, ptr->right);
        if(ptr->left){
            TreeNode* node = ptr->right;
            while(node->right)
                node = node->right;
            node->right = ptr->left;
        }
        ptr->left = NULL;
        ptr = ptr->right;
    }

    return root;
}
