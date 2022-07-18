int Solution::solve(vector<vector<int> > &matrix, int b) {
    int n = matrix.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + matrix[i][j];
        }
    }

    int ans = INT_MIN;
    for(int i=0; i+b-1<n; i++){
        for(int j=0; j+b-1<n; j++){
            int sum  = dp[i+b][j+b] - dp[i][j+b] - dp[i+b][j] + dp[i][j];
            ans = max(ans, sum);
        }
    }

    return ans;
}
