/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* helper(vector<int>& arr, int low, int high){
    if(high < low)
        return NULL;
    
    int ind = max_element(arr.begin()+low, arr.begin()+high+1) - arr.begin();
    TreeNode* node = new TreeNode(arr[ind]);
    node->left = helper(arr, low, ind-1);
    node->right = helper(arr, ind+1, high);

    return node;
}
TreeNode* Solution::buildTree(vector<int> &arr) {
    return helper(arr, 0, arr.size()-1);
}
