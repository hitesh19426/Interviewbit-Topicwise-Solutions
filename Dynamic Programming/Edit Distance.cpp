vector<vector<int>> dp;

int helper(string &a, string &b, int i, int j){
    if(i < 0 || j < 0)
        return (i<0 ? j+1 : i+1);
    if(dp[i][j] != INT_MAX)
        return dp[i][j];
    if(a[i] == b[j])
        dp[i][j] = helper(a, b, i-1, j-1);
    else
        dp[i][j] = min(min(helper(a, b, i-1, j), helper(a, b, i, j-1)), helper(a, b, i-1, j-1)) + 1;
    return dp[i][j];
}

int Solution::minDistance(string a, string b) {
    int m = a.size(), n = b.size();
    dp.assign(m, vector<int>(n, INT_MAX));
    return helper(a, b, m-1, n-1);
}
