bool check(vector<int>& arr, long long mid, long long B){
    long long count = 1, sum = 0;
    for(int x:arr){
        if(x > mid)
            return false;
        if(x+sum <= mid)
            sum += x;
        else
            sum = x, count++;
    }

    return count <= B;
}

int Solution::solve(vector<int> &A, int B) {
    long long sum = 0;
    for(int &a:A)
        sum += a;
    
    long long low = 0, high = sum, ans = -1;
    while(low <= high){
        long long mid = low + (high-low)/2;
        if(check(A, mid, B))
            ans = mid, high = mid-1;
        else
            low = mid+1;
    }

    return ans;
}
