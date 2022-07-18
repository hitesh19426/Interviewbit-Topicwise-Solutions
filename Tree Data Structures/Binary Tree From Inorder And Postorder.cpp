/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(vector<int>& postorder, int low, int high, int &root, unordered_map<int, int>& index){
    if(high < low)
        return NULL;

    int ind = index[postorder[root]];
    
    TreeNode* node = new TreeNode(postorder[root--]);
    node->right = helper(postorder, ind+1, high, root, index);
    node->left = helper(postorder, low, ind-1, root, index);
    
    return node;
}
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    if(inorder.empty())
        return NULL;

    unordered_map<int, int> index;
    for(int i=0; i<inorder.size(); i++){
        index[inorder[i]] = i;
    }

    int root = inorder.size()-1;
    return helper(postorder, 0, postorder.size()-1, root, index);
}
