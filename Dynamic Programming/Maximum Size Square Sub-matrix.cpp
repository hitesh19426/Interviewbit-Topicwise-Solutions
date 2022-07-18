int Solution::solve(vector<vector<int> > &arr) {
    int m = arr.size(), n = arr[0].size(), ans = 0;
    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(arr[i-1][j-1] == 1){
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans*ans;
}
