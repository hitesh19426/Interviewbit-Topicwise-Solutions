/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* root) {
    if(root == NULL)
        return {};

    vector<int> ans;

    while(root){
        ans.push_back(root->val);
        if(root->right == NULL)
            swap(root->right, root->left);
        if(root->left){
            auto node = root->right;
            while(node->left){
                node = node->left;
            }
            node->left = root->left;
        }
        root = root->right;
    }

    return ans;
}
