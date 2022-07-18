vector<vector<int>> dp;

int bottom_up(string &a, string &b, int i, int j){
    if(i<0 || j<0)
        return 0;
    if(dp[i][j] != INT_MIN)
        return dp[i][j];
    if(i==j)
        dp[i][j] = max(bottom_up(a, b, i-1, j), bottom_up(a, b, i, j-1));
    else if(a[i] == b[j])
        dp[i][j] = bottom_up(a, b, i-1, j-1) + 1;
    else
        dp[i][j] = max(bottom_up(a, b, i-1, j), bottom_up(a, b, i, j-1));
    return dp[i][j];
}

int Solution::anytwo(string a) {
    int n = a.size();
    dp.assign(n, vector<int>(n, INT_MIN));
    return bottom_up(a, a, n-1, n-1) > 1;
}
