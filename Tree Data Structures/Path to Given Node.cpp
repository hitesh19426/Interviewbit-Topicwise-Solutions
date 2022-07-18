/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool dfs(TreeNode* root, int k, vector<int>& path, bool found = true){
    if(root == NULL)
        return false;
        
    path.push_back(root->val);
    if(root->val == k)
        return true;

    if(dfs(root->left, k, path) || dfs(root->right, k, path)){
        return true;
    }
    path.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    dfs(A, B, path);
    return path;
}