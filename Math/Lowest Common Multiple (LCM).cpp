long Solution::solve(int a, int b) {
    long ans = (a/__gcd(a, b))*(long)b;
    return ans;
}
