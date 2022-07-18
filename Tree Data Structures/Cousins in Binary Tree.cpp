/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root, int target) {
    if(root == NULL)
        return {};

    bool found = false;
    queue<TreeNode*> queue;
    queue.push(root);

    while(not queue.empty() && !found){
        int size = queue.size();
        while(size--){
            auto node = queue.front();
            queue.pop();
            
            if((node->left && node->left->val == target) || (node->right && node->right->val == target)){
                found = true;
            }
            else{
                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }   
        }
    }

    vector<int> ans;
    while(not queue.empty()){
        ans.push_back(queue.front()->val);
        queue.pop();
    }

    return ans;
}