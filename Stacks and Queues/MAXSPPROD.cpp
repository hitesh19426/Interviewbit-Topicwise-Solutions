int Solution::maxSpecialProduct(vector<int> &arr) {
    int n = arr.size();
    vector<long long> greaterFromRight(n), greaterFromLeft(n);
    
    for(int i=0; i<n; i++){
        int left = i-1;
        while(left >=0 && arr[left] <= arr[i])
            left = greaterFromLeft[left];
        greaterFromLeft[i] = left;
    }

    for(int i=n-1; i>=0; i--){
        int right = i+1;
        while(right < n && arr[right] <= arr[i])
            right = greaterFromRight[right];
        greaterFromRight[i] = right;
    }

    long long ans = 0, mod = (1e9+7);
    for(int i=0; i<n; i++){
        if(greaterFromLeft[i] == -1 || greaterFromRight[i] == n)
            continue;
        ans = max(ans, greaterFromLeft[i]*greaterFromRight[i]);
    }

    return (int)(ans%mod);
}
