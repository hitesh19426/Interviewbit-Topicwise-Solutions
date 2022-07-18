int Solution::solve(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    for(int x: arr){
        if(x != arr[0] && x != arr[0]+k && x != arr[0]+2*k)
            return false;
    }
    return true;
}
