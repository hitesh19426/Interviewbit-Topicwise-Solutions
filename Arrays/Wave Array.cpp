vector<int> Solution::wave(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i=0; i<n; i+=2){
        if(i+1<n){
            swap(arr[i], arr[i+1]);
        }
    }

    return arr;
}
