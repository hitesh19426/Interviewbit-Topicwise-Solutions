const long long mod = (1e9+7);
long long helper(long long n, long long hsb=31){
    if(n<=1) return n;
    
    while(!(n&(1<<hsb)))
        hsb--;
    long long val = ((hsb-2)*(1<<(hsb-1))) + n+1 + helper(n^(1<<hsb), hsb-1);
    return val%mod;
}

int Solution::solve(int A) {
    return (int)helper(A)%mod;
}