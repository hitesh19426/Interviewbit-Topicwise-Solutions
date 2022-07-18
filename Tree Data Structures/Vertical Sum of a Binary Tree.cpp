/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfs(TreeNode* root, int level, map<int, int>& map){
    if(root == NULL)
        return;
    map[level] += root->val;
    dfs(root->left, level-1, map);
    dfs(root->right, level+1, map);
}

vector<int> Solution::verticalSum(TreeNode* root) {
    if(root == NULL)
        return {};

    vector<int> ans;
    map<int, int> map;

    dfs(root, 0, map);
    for(auto &pa: map)
        ans.push_back(pa.second);
    return ans;
}
