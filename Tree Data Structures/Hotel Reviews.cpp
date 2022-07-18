struct trieNode{
    trieNode* child[26];
    bool isEnd = false;

    trieNode(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }
};

void insert(trieNode* root, string& str){
    trieNode* ptr = root;
    for(char c: str){
        int index = c-'a';
        if(ptr->child[index] == NULL)
            ptr->child[index] = new trieNode();
        ptr = ptr->child[index];
    }
    ptr->isEnd = true;
}

bool search(trieNode* root, string& str){
    trieNode* ptr = root;
    for(char c: str){
        int index = c-'a';
        if(ptr->child[index] == NULL)
            return false;
        ptr = ptr->child[index];
    }
    return (ptr->isEnd);
}

int count(trieNode* root, string& str){
    int count = 0;
    string word = "";
    for(char c: str){
        if(c == '_'){
            if(search(root, word))
                count++;
            word = "";
        }
        else{
            word += c; 
        }
    }
    if(search(root, word))
        count++;
    return count;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    trieNode* root = new trieNode();
    
    string word = "";
    for(char c: A){
        if(c == '_'){
            insert(root, word);
            word = "";
        }
        else{
            word += c; 
        }
    }
    insert(root, word);

    int i = 0;
    vector<pair<int, int>> arr;
    for(auto &str: B){
        arr.push_back({count(root, str), i++});
    }

    sort(arr.begin(), arr.end(), [](auto &a, auto &b) -> bool {
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    });

    vector<int> ans;
    for(auto &pa: arr){
        ans.push_back(pa.second);
    }

    return ans;
}