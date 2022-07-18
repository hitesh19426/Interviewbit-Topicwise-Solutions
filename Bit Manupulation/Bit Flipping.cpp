int Solution::solve(int n) {
    int i = 31;
    while(not (n&(1<<i)))
        i--;
    while(i>=0)
        n ^= (1<<i), i--;
    return n;
}
