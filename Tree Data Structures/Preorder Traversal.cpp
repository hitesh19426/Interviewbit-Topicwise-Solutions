/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* root) {
    if(root == NULL)
        return {};
    
    vector<int> ans;

    while(root){
        ans.push_back(root->val);
        if(root->left == NULL)
            swap(root->left, root->right);
        if(root->right){
            auto node = root->left;
            while(node->right){
                node = node->right;
            }
            node->right = root->right;
        }
        root = root->left;
    }

    return ans;
}
