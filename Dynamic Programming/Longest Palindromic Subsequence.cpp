vector<vector<int>> dp;

int helper(string &s, int i, int j){
    if(i>j)
        return 0;
    if(i == j)
        return 1;
    if(dp[i][j] != INT_MAX)
        return dp[i][j];
    if(s[i] == s[j])
        dp[i][j] = helper(s, i+1, j-1) + 2;
    else
        dp[i][j] = max(helper(s, i+1, j), helper(s, i, j-1));
    return dp[i][j];
}

int Solution::solve(string s) {
    int n = s.size();
    dp.assign(n, vector<int>(n, INT_MAX));
    return helper(s, 0, n-1);
}
