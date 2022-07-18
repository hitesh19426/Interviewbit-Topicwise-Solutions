/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void min_max_level(TreeNode* root, int level, int &minlevel, int &maxlevel){
    if(root == NULL)
        return;
    minlevel = min(minlevel, level);
    maxlevel = max(maxlevel, level);

    min_max_level(root->left, level-1, minlevel, maxlevel);
    min_max_level(root->right, level+1, minlevel, maxlevel);
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    if(root == NULL)
        return {};
    
    int minlevel = INT_MAX, maxlevel = INT_MIN;
    min_max_level(root, 0, minlevel, maxlevel);

    vector<vector<int>> ans(maxlevel-minlevel+1, vector<int>());
    queue<pair<TreeNode*, int>> queue;
    queue.push({root, 0});
    
    while(not queue.empty()){
        auto front = queue.front();
        queue.pop();

        auto node = front.first;
        int level = front.second;
        ans[level - minlevel].push_back(node->val);

        if(node->left){
            queue.push({node->left, level-1});
        }
        if(node->right){
            queue.push({node->right, level+1});
        }
    }

    return ans;
}
