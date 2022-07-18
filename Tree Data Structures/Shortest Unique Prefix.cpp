struct trieNode{
    trieNode* child[26];
    bool covered = false;

    trieNode(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }
};

void insert(trieNode* root, string &s){
    trieNode* ptr = root;
    for(char c: s){
        int index = c - 'a';
        if(ptr->child[index] == NULL)
            ptr->child[index] = new trieNode();
        else
            ptr->child[index]->covered = true;
        ptr = ptr->child[index];
    }
}

string shortestUniquePrefix(trieNode* root, string &s){
    trieNode* ptr = root;
    string ans = "";

    for(char c: s){
        int index = c - 'a';
        if(ptr->child[index] == NULL)
            return "";
        ans += c;
        if(ptr->child[index]->covered == false)
            return ans;
        ptr = ptr->child[index];
    }
    return ans;
}

vector<string> Solution::prefix(vector<string> &A) {
    trieNode* root = new trieNode();
    
    for(string &s: A)
        insert(root, s);

    vector<string> ans;
    for(string &s: A)
        ans.push_back(shortestUniquePrefix(root, s));

    return ans;
}