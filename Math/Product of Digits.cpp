int Solution::solve(int n) {
    if(n == 0)
        return 0;
    int ans = 1;
    while(n){
        ans *= n%10;
        n /= 10;
    }
    return ans;
}
