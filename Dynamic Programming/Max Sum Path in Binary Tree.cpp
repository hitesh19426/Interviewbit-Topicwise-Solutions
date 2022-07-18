/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxRootToLeafSum(TreeNode* root, int &ans){
    if(root == NULL)
        return 0;
    
    int left = maxRootToLeafSum(root->left, ans);
    int right = maxRootToLeafSum(root->right, ans);
    
    int maxRootPath = max(max(left, right) + root->val, root->val);
    
    ans = max({ans, maxRootPath, root->val + left + right});
    return maxRootPath;
}

int Solution::maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxRootToLeafSum(root, ans);
    return ans;
}
