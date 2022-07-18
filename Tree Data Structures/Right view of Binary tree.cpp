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
        int size = queue.size();
        while(size--){
            auto node = queue.front();
            queue.pop();

            if(size == 0)
                ans.push_back(node->val);

            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
        }
    }

    return ans;
}
