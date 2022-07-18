bool check(vector<int>& arr, long long B, long long mid){
    long long sum = 0;
    for(int x:arr){
        sum += max(0ll, x-mid);
    }

    return sum >= B;
}

int Solution::solve(vector<int> &A, int B) {
    long long low = 0, high = *max_element(A.begin(), A.end()), ans = -1;
    while(low <= high){
        long long mid = low + (high-low)/2;
        if(check(A, B, mid))
            ans = mid, low = mid+1;
        else
            high = mid-1;
    }

    return ans;
}
