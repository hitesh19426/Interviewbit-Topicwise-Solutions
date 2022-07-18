int Solution::perfectPeak(vector<int> &arr) {
    int n = arr.size();
    int maxFromLeft[n], minFromRight[n];
    maxFromLeft[0] = arr[0], minFromRight[n-1] = arr[n-1];
    for(int i=1; i<n; i++){
        maxFromLeft[i] = max(maxFromLeft[i-1], arr[i]);
    }

    for(int i=n-2; i>=0; i--){
        minFromRight[i] = min(minFromRight[i+1], arr[i]);
    }
    

    for(int i=1; i<n-1; i++){
        if(maxFromLeft[i-1] < arr[i] && minFromRight[i+1] > arr[i])
            return true;
    }

    return false;
}
