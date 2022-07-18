long long nck[101][101];
long long ans[101];

long long helper(long long n){
    if(n == 1 || n == 2)
        return 1;
    if(n == 3)
        return 2;

    long long levels = (long long)log2(n) + 1;
    long long nodes_before_last_level = (1<<(levels-1))-1;
    long long nodes_in_last_level_on_left = n-nodes_before_last_level;
    long long total_nodes_in_last_level = (1<<(levels-1));
    if(nodes_in_last_level_on_left >= total_nodes_in_last_level/2)
        nodes_in_last_level_on_left = total_nodes_in_last_level/2;

    long long l = (1<<(levels-2))-1 + nodes_in_last_level_on_left, r = n-l-1;

    long long mod = (1e9+7);
    ans[n] = (((nck[n-1][l]*helper(l))%mod)*helper(r))%mod;
    return ans[n];
}

int Solution::solve(int A) {
    long long mod = 1e9+7;
    for(long long n=0; n<101; n++){
        for(long long k=0; k<=n; k++){
            if(k == 0 || n == k)
                nck[n][k] = 1;
            else
                nck[n][k] = nck[n-1][k] + nck[n-1][k-1];
            nck[n][k] %= mod;
        }
    }
    
    return helper(A);
}