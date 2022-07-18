int Solution::nTriang(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    long long count = 0, n = arr.size(), mod = (1e9+7);
    for(int i=0; i<n; i++){
        long long k = i+2;
        for(int j=i+1; j<n; j++){
            while(k<n && arr[k]<arr[j]+arr[i])
                k++;
            count += k-j-1;
            count %= mod;
        }
    }

    return (int)count;
}
