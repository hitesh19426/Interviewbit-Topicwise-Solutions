int Solution::solve(int a) {
    long long ans = 2, mod = 1e9+7;
    for(long long i=1; i<=a; i++)
        ans = (ans*i)%mod;
    return ans;
}
