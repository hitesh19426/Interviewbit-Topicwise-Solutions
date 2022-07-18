int Solution::solve(int a, int b, int c) {
    return ((a-1)%b+c-1)%(b)+1;
}
