string Solution::longestCommonPrefix(vector<string> &A) {
    if(A.empty())
        return "";
    
    int n = A.size();
    string prefix = "";

    for(int i=0; i<A[0].size(); i++){
        char current = A[0][i];
        for(int j=0; j<n; j++){
            if(A[j].size()<i){
                return prefix;
            }
            if(A[j][i] != current){
                return prefix;
            }
        }
        prefix += current;
    }
    return prefix;
}
