/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root) {
    if(root == NULL)
        return {};

    vector<int> ans;
    queue<TreeNode*> queue;
    queue.push(root);

    while(not queue.empty()){
        auto node = queue.front();
        queue.pop();

        ans.push_back(node->val);

        if(node->right)
            queue.push(node->right);
        if(node->left)
            queue.push(node->left);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
