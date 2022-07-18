int Solution::adjacent(vector<vector<int>> &arr) {
    int n = arr[0].size();
    int dp[n];

    int ans = 0;
    for(int i=0; i<n; i++){
        if(i==0){
            dp[i] = max(arr[0][i], arr[1][i]);
        }
        else if(i==1){
            dp[i] = max(dp[i-1], max(arr[0][i], arr[1][i]));
        }
        else{
            dp[i] = max(max(arr[0][i], arr[1][i]) + dp[i-2], dp[i-1]);
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}
