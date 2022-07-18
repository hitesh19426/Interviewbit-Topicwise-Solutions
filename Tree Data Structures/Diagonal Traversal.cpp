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
    map<int, vector<int>> map;
    stack<pair<TreeNode*, int>> stack;
    stack.push({root, 0});

    while(not stack.empty()){
        auto front = stack.top();
        stack.pop();

        auto node = front.first;
        auto level = front.second;

        map[level].push_back(node->val);

        if(node->right)
            stack.push({node->right, level});
        if(node->left)
            stack.push({node->left, level+1});
    }

    for(auto pa: map){
        for(int x: pa.second)
            ans.push_back(x);
    }
    return ans;
}
