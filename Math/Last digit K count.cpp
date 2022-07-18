int Solution::solve(int a, int b, int c) {
    while(a%10 != c)
        a++;
    while(b>=0 && b%10 != c)
        b--;
    if(b < a)
        return 0;
    return (b-a)/10+1;
}
