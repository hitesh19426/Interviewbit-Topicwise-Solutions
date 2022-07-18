int Solution::trailingZeroes(int n) {
    int ans = 0;
    for(int i=5; i<=n; i*=5){
        int x = i;
        while(x <= n)
            ans++, x += i;
    }
    return ans;
}
