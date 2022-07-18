pair<int, int> find_max_min(vector<int>& arr, int low, int high){
    if(low == high)
        return {arr[low], arr[low]};
    if(low+1 == high){
        if(arr[low] < arr[high])
            return {arr[low], arr[high]};
        return {arr[high], arr[low]};
    }
    
    int mid = (low+high)/2;
    auto left = find_max_min(arr, low, mid);
    auto right = find_max_min(arr, mid+1, high);
    return {min(left.first, right.first), max(left.second, right.second)};
}

int Solution::solve(vector<int> &arr) {
    auto max_min = find_max_min(arr, 0, arr.size()-1);
    return max_min.first + max_min.second;
}
