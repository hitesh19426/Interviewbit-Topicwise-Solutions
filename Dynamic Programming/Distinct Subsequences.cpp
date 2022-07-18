vector<vector<int>> dp;

int helper(string &a, string &b, int i, int j){
    if(i<0)
        return j<0;
    if(j<0)
        return 1;
    if(dp[i][j] != INT_MAX)
        return dp[i][j];
    if(a[i] == b[j])
        dp[i][j] = helper(a, b, i-1, j) + helper(a, b, i-1, j-1);
    else
        dp[i][j] = helper(a, b, i-1, j);
    return dp[i][j];
}

int Solution::numDistinct(string a, string b) {
    int m = a.size(), n = b.size();
    dp.assign(m, vector<int>(n, INT_MAX));
    return helper(a, b, m-1, n-1);
}
