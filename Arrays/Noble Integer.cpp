int Solution::solve(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i=0; i<n; i++){
        while(i+1<n && arr[i+1] == arr[i])
            i++;
        if(n-1-i == arr[i])
            return true;
    }
    return -1;
}
