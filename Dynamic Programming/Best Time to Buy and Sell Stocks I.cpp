int Solution::maxProfit(const vector<int> &arr) {
    int global_min = INT_MAX, ans = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] < global_min){
            global_min = arr[i];
        }
        else{
            ans = max(ans, arr[i]-global_min);
        }
    }

    return ans;
}
