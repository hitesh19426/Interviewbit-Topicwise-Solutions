int Solution::solve(vector<vector<int> > &arr) {
    vector<int> dp(arr.size());

    int len = 0;
    for(int i=0; i<arr.size(); i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j][1] < arr[i][0]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }

        len = max(len, dp[i]);
    }

    return len;
}
