int Solution::reverse(int n) {
    int ans = 0;
    while(n){
        int digit = n%10;
        if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > INT_MAX%10))
            return 0;
        if(ans < INT_MIN/10 || (ans == INT_MIN/10 && digit < INT_MIN%10))
            return 0;
        
        ans = 10*ans + digit;
        n /= 10;
    }
    
    return ans;
}
