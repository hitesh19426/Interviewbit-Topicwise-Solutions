int Solution::fibsum(int target) {
    vector<int> fib{1, 1};
    int n = fib.size();
    while(fib[n-1] + fib[n-2] <= target){
        fib.push_back(fib[n-1] + fib[n-2]);
        n = fib.size();
    }

    int ans = 0;
    int ind = fib.size()-1;
    while(target > 0){
        ans += target/fib[ind];
        target %= fib[ind];
        ind--;
    }

    return ans;
}
