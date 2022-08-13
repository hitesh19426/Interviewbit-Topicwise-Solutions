int Solution::solve(vector<int> &A) {
    int n = A.size(), sum = 0;
    for(int x: A)
        sum += x;
	bool dp[n+1][sum+1];
	    
    dp[0][0] = true;
    for(int i=1; i<=n; i++)
        dp[i][0] = false;
    for(int j=1; j<=sum; j++)
        dp[0][j] = false;
        
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=A[i-1])
                dp[i][j] |= dp[i-1][j-A[i-1]];
        }
    }
    
    int ans = INT_MAX;
    for(int j=0; j<=sum; j++){
        if(dp[n][j])
            ans = min(ans, abs(2*j - sum));
    }
    return ans;
}
