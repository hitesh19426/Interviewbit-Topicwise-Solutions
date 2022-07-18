vector<string> Solution::deserialize(string A) {
    vector<string> ans;
    int end = 0, len = A.size();
    while(end < len){
        string word="";
        while(isalpha(A[end])){
            word += A[end++];
        }
        while(!isalpha(A[end])){
            end++;
        }
        ans.push_back(word);
    }
    return ans;
}
