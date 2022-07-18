int Solution::firstMissingPositive(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]<=0 || arr[i] > n)
            arr[i] = n+1;
    }
    for(int i=0; i<n; i++){
        int ind = abs(arr[i])-1;
        if(ind < n){
            arr[ind] = -abs(arr[ind]);
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i] > 0)
            return i+1;
    }
    return n+1;
}
