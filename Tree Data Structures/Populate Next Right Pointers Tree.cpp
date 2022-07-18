/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* root) {
    while(root){
        TreeLinkNode* nexthead = NULL, *prev = NULL;
        while(root){
            
            if(root->left){
                if(prev == NULL)
                    nexthead = root->left;
                else
                    prev->next = root->left;
                prev = root->left;
            }

            if(root->right){
                if(prev == NULL)
                    nexthead = root->right;
                else
                    prev->next = root->right;
                prev = root->right;
            }

            root = root->next;
        }

        root = nexthead;
    }
}
