bool check(vector<int>& arr, long long time, long long time_max, long long painters){
    long long sum = 0, count = 1;
    for(long long len: arr){
        if(len*time > time_max)
            return false;
        if(time*len + sum <= time_max)
            sum += time*len;
        else
            sum = time*len, count++;
    }

    return count <= painters;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long low = 1, high = LLONG_MAX, time = -1;
    while(low <= high){
        long long mid = (low+high)/2;
        if(check(C, B, mid, A))
            time = mid, high = mid-1;
        else
            low = mid+1;
    }

    return time%10000003;
}
