int Solution::solve(vector<vector<int> > &grid) {
    int m = grid.size(), n = grid[0].size(), ans = INT_MIN;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1] + grid[i][j];
            ans = max(ans, dp[i][j]);
        }
    }
    
    return ans;
}
