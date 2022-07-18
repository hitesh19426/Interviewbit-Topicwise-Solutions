long Solution::solve(int a, int b) {
    long long first = 7*(b/7), last = 7*(a%7==0 ? a/7 : a/7+1);
    
    long long n = b/7 - (a%7==0 ? a/7 : a/7+1) + 1;
    
    return (n*(first+last))/2;
}
