int Solution::maxProfit(const vector<int> &arr) {
    int ans = 0, n = arr.size();
    for(int i=0; i<n-1; i++){
        if(arr[i] < arr[i+1])
            ans += arr[i+1] - arr[i];
    }

    return ans;
}
