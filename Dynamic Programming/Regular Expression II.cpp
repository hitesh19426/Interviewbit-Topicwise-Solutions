int Solution::isMatch(const string s, const string p) {
    int m = s.size(), n = p.size();
    vector<bool> prev(n+1, false);
    
    prev[0] = true;
    for(int j=1; j<=n; j++)
        prev[j] = (p[j-1]=='*' && prev[j-2]);
    
    for(int i=1; i<=m; i++){
        vector<bool> curr(n+1, false);
        for(int j=1; j<=n; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '.')
                curr[j] = prev[j-1];
            else if(p[j-1] == '*'){
                curr[j] = curr[j-2] || curr[j-1];
                if(s[i-1] == p[j-2] || p[j-2] == '.')
                    curr[j] = curr[j] || prev[j];
            }
        }
        prev = curr;
    }
    
    return prev.back();
}
