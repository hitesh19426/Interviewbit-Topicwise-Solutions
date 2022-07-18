int Solution::solve(vector<int> &arr) {
    vector<int> right(arr.size());
    for(int i=arr.size()-1; i>=0; i--){
        right[i] = (i == arr.size()-1 ? arr[i] : max(arr[i], right[i+1]));
    }

    multiset<int, greater<int>> left;

    int ans = 0;
    for(int i=1; i<arr.size()-1; i++){
        left.insert(arr[i-1]);
        auto left_idx = left.upper_bound(arr[i]);
        auto right_idx = right[i+1];

        if(left_idx != left.end() && right_idx > arr[i]){
            ans = max(ans, arr[i] + *left_idx + right_idx);
        }
    }

    return ans;
}
