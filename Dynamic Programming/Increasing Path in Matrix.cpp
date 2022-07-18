int Solution::solve(vector<vector<int>> &arr) {
    int n = arr.size(), m = arr[0].size(), ans = -1;
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i!=0 && arr[i-1][j] < arr[i][j] && dp[i-1][j] != INT_MAX){
                dp[i][j] = dp[i-1][j] + 1;
            }
            if(j!=0 && arr[i][j-1] < arr[i][j] && dp[i][j-1] != INT_MAX){
                if(dp[i][j] != INT_MAX){
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
                }
                else{
                    dp[i][j] = dp[i][j-1] + 1;
                }
                
            }
        }
    }

    return dp[n-1][m-1] == INT_MAX ? -1 : dp[n-1][m-1];
}
