int binary_search(int arr[], int n, int low, int target){
    int ans = -1, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] >= target)
            ans = mid, low=mid+1;
        else
            high=mid-1;
    }
    return ans;
}

int Solution::maximumGap(const vector<int> &arr) {
    int n = arr.size();
    int max_suffix[n];
    max_suffix[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        max_suffix[i] = max(max_suffix[i+1], arr[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int ind = binary_search(max_suffix, n, i+1, arr[i]);
        ans = max(ans, ind-i);
    }

    return ans;
}
