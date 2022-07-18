struct trieNode{
    trieNode* child[2] = {NULL, NULL};
    int val = 0;
};

void insert(trieNode* root, int x){
    trieNode* ptr = root;
    for(int i=31; i>=0; i--){
        bool digit = x&(1<<i);
        if(ptr->child[digit] == NULL)
            ptr->child[digit] = new trieNode();
        ptr = ptr->child[digit];
    }
    ptr->val = x;
}

int maxXor(trieNode* root, int x){
    trieNode* ptr = root;
    for(int i=31; i>=0; i--){
        bool digit = x&(1<<i);
        if(ptr->child[1-digit] != nullptr)
            ptr = ptr->child[1-digit];
        else
            ptr = ptr->child[digit];
    }
    return x^(ptr->val);
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    trieNode* root = new trieNode();

    for(int x:A){
        insert(root, x);
    }

    int ans = 0;
    for(int x: B){
        ans = max(ans, maxXor(root, x));
    }

    return ans;
}