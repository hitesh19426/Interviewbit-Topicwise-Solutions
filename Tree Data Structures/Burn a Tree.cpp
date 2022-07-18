/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct info{
    int time = 0, depth = 0, fire = 0;
};

void helper(TreeNode* root, int target, info &i, int &ans){
    if(root == NULL){
        i.depth = 0, i.fire = false, i.time = 0;
        return;
    }
    
    info infol, infor;
    helper(root->left, target, infol, ans);
    helper(root->right, target, infor, ans);

    i.depth = max(infol.depth, infor.depth) + 1;
    if(root->val == target)
        i.fire = true;
    if(infol.fire){
        i.fire = true;
        i.time = infol.time+1;
        ans = max(ans, i.time + infor.depth);
    }
    if(infor.fire){
        i.fire = true;
        i.time = infor.time+1;
        ans = max(ans, i.time + infol.depth);
    }
}

int Solution::solve(TreeNode* root, int target) {
    int ans = 0;
    info i;
    helper(root, target, i, ans);
    return ans;
}
