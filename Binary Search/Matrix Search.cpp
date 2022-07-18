int Solution::searchMatrix(vector<vector<int> > &arr, int B) {
    int row = arr.size(), col = arr[0].size(), low = 0, high = row*col-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid/col][mid%col] == B){
            return 1;
        }
        else if(arr[mid/col][mid%col] < B){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return 0;
}
