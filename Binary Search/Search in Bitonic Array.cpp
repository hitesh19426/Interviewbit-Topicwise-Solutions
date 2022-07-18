int binary_search_in_left_half(vector<int>& arr, int low, int high, int target){
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int binary_search_in_right_half(vector<int>& arr, int low, int high, int target){
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] < target)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int Solution::solve(vector<int> &arr, int target) {
    int low = 0, high = arr.size()-1, peak = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(mid == 0 || arr[mid] > arr[mid-1])
            peak = mid, low = mid+1;
        else
            high = mid-1;
    }
    
    int resInLeft = binary_search_in_left_half(arr, 0, peak, target);
    if(resInLeft != -1)
        return resInLeft;
    return binary_search_in_right_half(arr, peak+1, arr.size()-1, target);
}
