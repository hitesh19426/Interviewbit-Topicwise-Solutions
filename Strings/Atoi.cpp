int Solution::atoi(const string A) {
    int i = 0, sign = 1;
    while(i<A.size() && A[i] == ' ')
        i++;

    if(i<A.size() && (A[i] == '+' || A[i] == '-') ){
        sign = (A[i] == '+' ? 1 : -1);
        i++;
    }

    long long ans = 0;
    while(i<A.size() && isdigit(A[i])){
        ans = ans*10 + sign*(A[i]-'0');
        if(ans > INT_MAX){
            return INT_MAX;
        }
        if(ans < INT_MIN)
            return INT_MIN;
        i++;
    }
    return (int)ans;
}
