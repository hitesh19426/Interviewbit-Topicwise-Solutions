int Solution::addNumbers(int a, int b) {
    int ans = 0;
    for(int i=0, carry = 0; i<31; i++){
        bool bit1 = a&(1<<i), bit2 = b&(1<<i);
        bool sum = (bit1+bit2+carry)%2;
        carry = (bit1+bit2+carry)/2;
        if(sum)
            ans |= (1<<i);
    }
    
    return ans;
}
