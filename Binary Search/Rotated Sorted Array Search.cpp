int binary_search(const vector<int>& arr, int low, int high, int target){
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int Solution::search(const vector<int> &arr, int B) {
    int low = 0, high = arr.size()-1, index = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= arr[0])
            index = mid, low = mid+1;
        else{
            high = mid-1;
        }
    }

    int left = binary_search(arr, 0, index, B);
    if(left != -1)
        return left;

    // index = (index == -1 ? 0 : index);
    return binary_search(arr, index+1, arr.size()-1, B);
}