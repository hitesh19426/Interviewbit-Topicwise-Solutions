/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode* root, int parent_node, unordered_map<int, int> &parent,  map<int, TreeNode*> &nodes){
    if(root == NULL)
        return;
    parent[root->val] = parent_node;
    nodes[root->val] = root;
    dfs(root->left, root->val, parent, nodes);
    dfs(root->right, root->val, parent, nodes);
}

vector<int> Solution::distanceK(TreeNode* A, int target, int k) {
    unordered_map<int, int> parent;
    map<int, TreeNode*> nodes;
    
    dfs(A, -1, parent, nodes);
     
    TreeNode *target_node = nodes[target];

    vector<int> ans;
    vector<bool> vis(parent.size()+1, false);
    queue<TreeNode*> queue;
    queue.push(target_node);
    vis[target] = true;
    int distance = 0;

    while(not queue.empty()){
        int size = queue.size();
        while(size--){
            auto front = queue.front();
            queue.pop();

            if(distance == k){
                ans.push_back(front->val);
            }

            if(front->left && !vis[front->left->val]){
                queue.push(front->left);
                vis[front->left->val] = true;
            }
            if(front->right && !vis[front->right->val]){
                queue.push(front->right);
                vis[front->right->val]= true;
            }
            if(parent[front->val] != -1 && !vis[parent[front->val]]){
                queue.push(nodes[parent[front->val]]);
                vis[parent[front->val]] = true;
            }
        }
        distance++;
        if(distance>k)
            break;
    }

    return ans;
}
