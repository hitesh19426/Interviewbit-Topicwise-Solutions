/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(vector<int>& pre, int low, int high, int &root, unordered_map<int, int> &index){
    if(high < low)
        return NULL;
    
    int ind = index[pre[root]];
    TreeNode* node = new TreeNode(pre[root++]);
    node->left = helper(pre, low, ind-1, root, index);
    node->right = helper(pre, ind+1, high, root, index);
    return node;
}
TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &inorder) {
    if(pre.empty())
        return NULL;
    
    unordered_map<int, int> index;
    for(int i=0; i<inorder.size(); i++)
        index[inorder[i]] = i;

    int root = 0;
    return helper(pre, 0, pre.size()-1, root, index);
}
