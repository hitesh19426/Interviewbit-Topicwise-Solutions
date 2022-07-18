bool check(vector<vector<int>>& matrix, int mid, int target){
    int count = 0;
    for(auto &row: matrix)
        count += upper_bound(row.begin(), row.end(), mid) - row.begin();
    return count >= target;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int row = A.size(), col = A[0].size(), low = INT_MAX, high = 0;
    for(auto &row: A){
        low = min(low, row[0]);
        high = max(high, row[col-1]);
    }

    int target = (row*col+1)/2, median = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(check(A, mid, target))
            median = mid, high = mid-1;
        else
            low = mid+1;
    }

    return median;
}
