int Solution::uniquePaths(int A, int B) {
    vector<int> dp(B, 1);

    for(int i=1; i<A; i++){
        for(int j=1; j<B; j++){
            dp[j] += dp[j-1];
        }
    }

    return dp.back();
}
