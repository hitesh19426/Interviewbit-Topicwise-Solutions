/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long Solution::coveredNodes(TreeNode* root) {
    if(root == NULL)
        return 0;

    long ans = 0, covered = 0, uncovered = 0;
    queue<TreeNode*> queue;
    queue.push(root);

    while(not queue.empty()){
        int size = queue.size();
        for(int i=0; i<size; i++){
            auto node = queue.front();
            queue.pop();

            if(i == size-1 || i == 0){
                uncovered += node->val;
            }
            else{
                covered += node->val;
            }

            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
        }
    }

    return abs(covered-uncovered);
}
