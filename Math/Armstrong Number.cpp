int length(int n){
    int ans = 0;
    while(n)
        n /= 10, ans++;
    return ans;
}

int pow(int a, int n){
    int ans = 1, power = 1;
    while(n){
        if(n&1)
            ans *= a;
        a *= a;
        n /= 2;
    }
    return ans;
}

int Solution::solve(int n) {
    int len = length(n);
    int num = 0, n_copy = n;
    while(n){
        num += pow(n%10, len);
        n /= 10;
    }
    return num == n_copy;
}
