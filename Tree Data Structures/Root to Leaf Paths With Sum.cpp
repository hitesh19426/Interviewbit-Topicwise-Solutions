/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isleaf(TreeNode* root){
    return (root->left == NULL && root->right == NULL);
}
void helper(TreeNode* root, int target, vector<int> stack, vector<vector<int>>& ans){
    stack.push_back(root->val);
    if(isleaf(root)){
        if(root->val == target)
            ans.push_back(stack);
        stack.pop_back();
        return;
    }

    if(root->left){
        helper(root->left, target - root->val, stack, ans);
    }

    if(root->right){
        helper(root->right, target - root->val, stack, ans);
    }

    stack.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int target) {
    vector<vector<int>> ans;
    vector<int> stack;
    helper(root, target, stack, ans);
    return ans;
}
