vector<vector<vector<int>>> dp;

bool helper(const string &a, const string &b, int i, int j, int len){
    if(len == 1)
        return a[i] == b[j];
    if(dp[i][j][len] != -1)
        return dp[i][j][len];

    dp[i][j][len] = false;
    for(int k=1; k<len; k++){
        dp[i][j][len] |= helper(a, b, i, j, k) && helper(a, b, i+k, j+k, len-k);
        dp[i][j][len] |= helper(a, b, i, j+len-k, k) && helper(a, b, i+k, j, len-k);
    }

    return dp[i][j][len];
}

int Solution::isScramble(const string a, const string b) {
    if(a.size() != b.size())
        return false;
    
    int n = a.size();
    dp.assign(n, vector<vector<int>>(n, vector<int>(n+1, -1)));
    return helper(a, b, 0, 0, n);
}
