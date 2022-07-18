int Solution::uniquePathsWithObstacles(vector<vector<int>> &arr) {
    int m = arr.size(), n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1){
                continue;
            }
            if(i==0 && j==0){
                dp[i][j] = 1;
            }
            if(i!=0 && dp[i-1][j] != 0){
                dp[i][j] += dp[i-1][j];
            }
            if(j!=0 && dp[i][j-1] != 0){
                dp[i][j] += dp[i][j-1];
            }
        }
    }

    return dp.back().back();
}
