const int maxn = 1005;
int dp[maxn][maxn];

int Solution::solve(vector<vector<int> > &arr) {
    int n = arr.size();
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = arr[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j != 0){
                dp[i][j] = arr[i][j] + dp[i-1][j-1];
            }
            if(i != j){
                dp[i][j] = max(dp[i][j], arr[i][j] + dp[i-1][j]);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[n-1][i]);
    }

    return ans;
}
