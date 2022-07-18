/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator{
private:
    stack<TreeNode*> stack;
    TreeNode* root;
public:
    BSTIterator::BSTIterator(TreeNode *root);
    bool BSTIterator::hasNext();
    int BSTIterator::next();
};


BSTIterator::BSTIterator(TreeNode *root) : root(root) {
    while(not stack.empty())
        stack.pop();
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return (root != NULL || !stack.empty());
}

/** @return the next smallest number */
int BSTIterator::next() {
    while(root){
        stack.push(root);
        root = root->left;
    }
    root = stack.top();
    stack.pop();
    int ans = root->val;
    root = root->right;
    return ans;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
