int Solution::solve(vector<int> &arr, int day, int fine) {
    int ans = 0;
    for(int digit: arr){
        if((digit&1 && day%2 == 0) || (digit%2==0 && day&1))
            ans += fine;
    }
    return ans;
}
