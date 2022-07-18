/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* root) {
    if(root == NULL)
        return {};
    
    vector<int> ans;

    while(root){
        if(root->left){
            auto node = root->left;
            while(node->right)
                node = node->right;
            node->right = root;
            root->left = NULL;
            root = node;
            continue;
        }
        ans.push_back(root->val);
        root = root->right;
    }

    return ans;
}
