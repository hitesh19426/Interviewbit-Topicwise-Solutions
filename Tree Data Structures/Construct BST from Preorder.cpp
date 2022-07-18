/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(vector<int>& preorder, unordered_map<int, int>& index, int &root, int low, int high ){
    if(high < low)
        return NULL;

    int ind = index[preorder[root]];
    TreeNode* node = new TreeNode(preorder[root++]);
    node->left = helper(preorder, index, root, low, ind-1);
    node->right = helper(preorder, index, root, ind+1, high);

    return node;
}

TreeNode* Solution::constructBST(vector<int> &preorder) {
    vector<int> inorder(preorder);
    unordered_map<int, int> index;
    sort(inorder.begin(), inorder.end());

    for(int i=0; i<inorder.size(); i++){
        index[inorder[i]] = i;
    }

    int root = 0;
    return helper(preorder, index, root, 0, inorder.size()-1);
}
