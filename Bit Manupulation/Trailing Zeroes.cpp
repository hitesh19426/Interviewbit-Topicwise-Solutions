int Solution::solve(int A) {
    int i = 0;
    while(i<32 && !(A&(1<<i)))
        i++;
    return i;
}
