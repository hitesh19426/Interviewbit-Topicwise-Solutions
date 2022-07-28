int Solution::solve(vector<int> &prices, int k) {
    int n = prices.size(), start = 0;
    k = min(k, n+1);
    int held[n+1][k+1], sold[n+1][k+1];
    for(int i=0; i<=n; i++)
        held[i][0] = INT_MIN, sold[i][0] = 0;
    for(int i=0; i<=k; i++)
        held[0][i] = INT_MIN, sold[0][i] = 0;
    
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){                
            held[i][j] = max(held[i-1][j], sold[i-1][j-1] - prices[i-1]);
            sold[i][j] = max(sold[i-1][j], held[i-1][j] + prices[i-1]);
            ans = max(ans, sold[i][j]);
        }
    }
    
    return ans;
}
