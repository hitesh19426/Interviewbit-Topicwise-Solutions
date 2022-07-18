bool check(vector<int>& arr, long long max_pages, long long k){
    long long count = 1, sum = 0;
    for(auto pages: arr){
        if(pages > max_pages)
            return false;
        if(pages + sum <= max_pages)
            sum += pages;
        else
            sum = pages, count++;
    }

    return count <= k;
}

int Solution::books(vector<int> &A, int B) {
    if(B > A.size())
        return -1;
    long long low = 1, high = 0, ans = -1;
    for(auto pages:A)
        high += pages;
    
    while(low <= high){
        long long mid = (low+high)/2;
        if(check(A, mid, B))
            ans = mid, high = mid-1;
        else
            low = mid+1;
    }

    return ans;
}