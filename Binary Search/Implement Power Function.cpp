int helper(long long x, long long n, long long d){
    long long ans = 1%d;
    while(n){
        if(n&1)
            ans = (ans*x%d+d)%d;
        x = (x*x%d+d)%d;
        n /= 2;
    }
    return ans;
}

int powmod(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return helper(x, n, d);
}
