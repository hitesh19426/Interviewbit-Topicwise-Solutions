int Solution::minPathSum(vector<vector<int>> &arr) {
    int m = arr.size(), n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = arr[0][0];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i!=0){
                dp[i][j] = min(dp[i][j], arr[i][j] + dp[i-1][j]);
            }
            if(j!=0){
                dp[i][j] = min(dp[i][j], arr[i][j] + dp[i][j-1]);
            }
        }
    }

    return dp.back().back();
}
