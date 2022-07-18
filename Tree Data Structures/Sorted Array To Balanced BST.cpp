/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(const vector<int>& arr, int low, int high){
    if(low > high)
        return NULL;

    int mid = (low+high)/2;
    TreeNode* node = new TreeNode(arr[mid]);
    node->left = helper(arr, low, mid-1);
    node->right = helper(arr, mid+1, high);

    return node;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &arr) {
    if(arr.empty())
        return NULL;
    return helper(arr, 0, arr.size()-1);
}
