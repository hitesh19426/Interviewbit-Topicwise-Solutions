int Solution::solve(vector<int> &arr) {
    int n = arr.size(), odd = 0, even = 0;
    vector<int> dp(n+4, 0), odd_even(2, 0);

    for(int i=0; i<n; i++){
        dp[i+2] = dp[i] + arr[i];
        odd_even[1-i%2] += arr[i];
    }

    int count = 0;
    for(int i=2; i<=n+1; i++){
        if(dp[i-1] + odd_even[1-i%2] - dp[i] == dp[i-2] + odd_even[(i%2)] - dp[i-1])
            count++;
    }

    return count;
}
