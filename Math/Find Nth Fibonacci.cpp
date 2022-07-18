const long long mod = (1e9+7);
typedef vector<vector<long long>> vvll;

vvll multiply(vvll& a, vvll& b){
    vvll ans(2, vector<long long>(2, 0));
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                ans[i][j] += a[i][k]*b[k][j];
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}

int Solution::solve(int n) {
    if(n<=2)
        return 1;
    n-=2;
    vvll a{{1, 1}, {1, 0}};
    vvll ans{{1, 0}, {0, 1}};
    while(n){
        if(n&1)
            ans = multiply(ans, a);
        a = multiply(a, a);
        n /= 2;
    }

    return (ans[0][0] + ans[0][1])%mod;
}
