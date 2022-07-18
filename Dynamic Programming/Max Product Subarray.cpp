int Solution::maxProduct(const vector<int> &arr) {
    if(arr.empty())
        return 0;

    int min_so_far = 1, max_so_far = 1, ans = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] < 0)
            swap(min_so_far, max_so_far);

        min_so_far = min(min_so_far*arr[i], arr[i]);
        max_so_far = max(max_so_far*arr[i], arr[i]);
        ans = max(ans, max_so_far);
    }

    return ans;
}
