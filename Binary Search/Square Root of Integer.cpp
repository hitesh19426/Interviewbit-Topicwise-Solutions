int Solution::sqrt(int A) {
    if(A <= 1){
        return A;
    }

    int low = 1, high = A, ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(mid <= A/mid)
            ans = mid, low = mid+1;
        else
            high = mid-1;
    }

    return ans;
}
