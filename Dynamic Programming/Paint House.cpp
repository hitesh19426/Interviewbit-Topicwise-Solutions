int Solution::solve(vector<vector<int> > &arr) {
    int n = arr.size();
    int dp[n][3];
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            if(i==0){
                dp[i][j] = arr[i][j];
            }
            else{
                dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + arr[i][j];
            }
        }
    }

    return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}
