int Solution::solve(const vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    unordered_map<int, int> pos;

    int ans = 1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int prev = arr[i] + (arr[i] - arr[j]);
            if(pos.find(prev) == pos.end()){
                dp[i][j] = 2;
            }
            else{
                dp[i][j] = dp[pos[prev]][i]+1;
            }
            ans = max(dp[i][j], ans);
        }
        pos[arr[i]] = i;
    }

    return ans;
}
