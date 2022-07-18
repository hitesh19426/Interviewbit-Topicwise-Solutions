int Solution::cpFact(int n, int b) {
    while(__gcd(n, b) != 1)
        n /= __gcd(n, b);
    return n;
}
