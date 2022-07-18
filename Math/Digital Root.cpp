int Solution::solve(int n) {
    while(n>=10){
        int sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }
        n = sum;
    }
    return n;
}
