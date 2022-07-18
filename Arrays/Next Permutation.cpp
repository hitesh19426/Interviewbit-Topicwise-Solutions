int binary_search(vector<int>& arr, int low, int high, int target){
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > target)
            ans = mid, low = mid+1;
        else
            high = mid-1;
    }
    return ans;
}

vector<int> Solution::nextPermutation(vector<int> &A) {
    int i = A.size()-2;
    while(i>=0 && A[i] > A[i+1])
        i--;
    
    if(i>=0){
        int ind = binary_search(A, i+1, A.size()-1, A[i]);
        swap(A[i], A[ind]);
    }

    reverse(A.begin()+i+1, A.end());
    return A;
}
