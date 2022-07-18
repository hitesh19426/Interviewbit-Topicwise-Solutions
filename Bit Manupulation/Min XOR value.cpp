struct trieNode{
    unordered_map<bool, trieNode*> nodes;
    int val;
};

void insert(trieNode* root, int value){
    trieNode* ptr = root;
    for(int i=31; i>=0; i--){
        bool index = (value & (1<<i));
        if(ptr->nodes.find(index) == ptr->nodes.end()){
            ptr->nodes[index] = new trieNode();
        }
        ptr = ptr->nodes[index];
    }
    ptr->val = value;
}

int min_xor_from_trie(trieNode* root, int value){
    trieNode* ptr = root;
    for(int i=31; i>=0; i--){
        bool index = (value & (1<<i));
        if(ptr->nodes.find(index) != ptr->nodes.end()){
            ptr = ptr->nodes[index];
        }
        else{
            ptr = ptr->nodes[1-index];
        }
    }
    return value^(ptr->val);
}

int Solution::findMinXor(vector<int> &A) {
    int n = A.size(), min_xor = INT_MAX;
    
    trieNode* root = new trieNode();
    insert(root, A[0]);

    for(int i=1; i<n; i++){
        min_xor = min(min_xor, min_xor_from_trie(root, A[i]));
        insert(root, A[i]);
    }

    return min_xor;
}
