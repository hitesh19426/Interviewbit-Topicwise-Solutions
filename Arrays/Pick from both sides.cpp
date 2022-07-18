int Solution::solve(vector<int> &arr, int b) {
    int n = arr.size();
    int prefix[n+1], suffix[n+1];
    
    prefix[0] = 0, prefix[1] = arr[0], suffix[n-1] = arr[n-1], suffix[n] = 0;
    for(int i=2; i<=n; i++){
        prefix[i] = prefix[i-1]+arr[i-1];
    }
    for(int i=n-2; i>=0; i--){
        suffix[i] = suffix[i+1]+arr[i];
    }

    int ans = INT_MIN;
    for(int i=0; i<=b; i++){
        ans = max(ans, prefix[b-i] + suffix[n-i]);
    }

    return ans;
}
