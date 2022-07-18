int Solution::solve(int n) {
    n = abs(n);
    long long sum = 0, ans = 0, i = 1;
    while(sum < n || (sum-n)&1)
        sum += i, ans++, i++;

    return ans;
}
