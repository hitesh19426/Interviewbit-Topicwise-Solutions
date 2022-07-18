int Solution::solve(int n, vector<int> &arr) {
    int prefix[n], sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        prefix[i] = sum;
    }
    if(sum%3 != 0)
        return 0;
    
    int next = 0, suffix_sum = 0, suffix[n];
    for(int i=n-1; i>=0; i--){
        suffix_sum += arr[i];
        suffix[i] = (suffix_sum == sum/3 ? ++next : next);
    }

    int ans = 0;
    for(int i=0; i+2<n; i++){
        if(prefix[i] == sum/3){
            ans += suffix[i+2];
        }
    }
    return ans;
}
