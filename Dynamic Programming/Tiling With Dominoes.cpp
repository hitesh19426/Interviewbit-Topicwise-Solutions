int Solution::solve(int n) {
    if(n&1)
        return 0;
    
    long long full[n+1], lower[n+1];
    long long mod =  1e9+7;
    full[1] = 0, full[2] = 3;
    lower[1] = 1, lower[2] = 0;

    for(int i=3; i<=n; i++){
        full[i] = full[i-2] + 2*lower[i-1];
        lower[i] = full[i-1] + lower[i-2];

        full[i] %= mod;
        lower[i] %= mod;
    }

    return (full[n] + lower[n])%mod;
}
