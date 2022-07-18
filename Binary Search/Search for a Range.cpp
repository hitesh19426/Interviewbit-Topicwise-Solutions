int lower_index(const vector<int>& arr, int target){
    int low = 0, high = arr.size()-1, ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            ans = mid, high = mid-1;
        }
        else if(arr[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return ans;
}

int high_index(const vector<int>& arr, int target){
    int low = 0, high = arr.size()-1, ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            ans = mid, low = mid+1;
        }
        else if(arr[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return ans;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int first = lower_index(A, B);
    if(first == -1)
        return {-1, -1};

    return {first, high_index(A, B)};
}