int Solution::solve(int A, int B, int C) {
    B--; C--;
    bool bitB = A&(1<<B), bitC = A&(1<<C);
    if(bitB == bitC)
        return A;
    A ^= (1<<B)^(1<<C);
    return A;
}
