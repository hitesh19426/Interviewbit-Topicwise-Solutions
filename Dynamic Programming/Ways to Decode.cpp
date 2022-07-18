const int maxn = 1e5+5, mod = 1e9+7;
long long dp[maxn];

long long helper(string &s, int i){
    if(i<0)
        return 1;
    if(dp[i] != -1)
        return dp[i];

    dp[i] = 0;
    if(s[i] >= '1')
        dp[i] += helper(s, i-1);
    if(i>0 && s[i-1] == '1')
        dp[i] += helper(s, i-2);
    if(i>0 && s[i-1] == '2' && s[i] <= '6')
        dp[i] += helper(s, i-2);
    
    dp[i] %= mod;
    return dp[i];
}

int Solution::numDecodings(string s) {
    int n = s.size();
    memset(dp, -1, sizeof(dp));
    return helper(s, n-1);
}
