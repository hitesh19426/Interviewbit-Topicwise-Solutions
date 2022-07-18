int Solution::chordCnt(int n) {
    long long dp[n+1];
    const long long mod = 1e9+7;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[i-1-j]*dp[j];
            dp[i] %= mod;
        }
        dp[i] %= mod;
    }

    return dp[n];
}
