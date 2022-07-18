/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    if(root == NULL)
        return {};

    vector<vector<int>> ans;
    queue<TreeNode*> queue;
    queue.push(root);

    bool rev = false;
    while(not queue.empty()){
        int size = queue.size();
        vector<int> level;
        while(size--){
            auto node = queue.front();
            queue.pop();

            level.push_back(node->val);
            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
        }
        if(rev)
            reverse(level.begin(), level.end());
        ans.push_back(level);
        rev = !rev;
    }

    return ans;
}
