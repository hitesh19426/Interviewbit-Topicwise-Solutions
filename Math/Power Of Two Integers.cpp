int Solution::isPower(int n) {
    if(n<=3)
        return (n == 1 ? true : false);
    
    map<int, int> factors;
    for(int i=2; i<=n; i++){
        while(n%i == 0)
            factors[i]++, n /= i;
    }

    int gcd = 0;
    for(auto pa: factors){
        gcd = __gcd(pa.second, gcd);
    }

    if(gcd == 1)
        return false;
    return true;
}
