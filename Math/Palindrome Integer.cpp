int pow(int n, int i){
    int ans = 1;
    while(i){
        ans *= 10;
        i--;
    }
    return ans;
}

int digit(int n, int i){
    return (n/pow(10, i))%10;
}

int Solution::isPalindrome(int n) {
    if(n<0)
        return false;
        
    int num = n, len = 0;
    while(num){
        num /= 10;
        len++;
    }

    for(int i=0; i<len/2; i++){
        if(digit(n, i) != digit(n, len-1-i))
            return false;
    }
    return true;
}
