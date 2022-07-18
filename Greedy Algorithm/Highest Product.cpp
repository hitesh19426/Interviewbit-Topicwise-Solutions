int Solution::maxp3(vector<int> &arr) {
    if(arr.size() <= 3u){
        int ans = 1;
        for(int x: arr)
            ans *= x;
        return ans;
    }

    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    int m1 = arr[0]*arr[1]*arr[n-1];
    int m2 = arr[n-1]*arr[n-2]*arr[n-3];
    return max(m1, m2);
}