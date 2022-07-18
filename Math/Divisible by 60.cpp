int Solution::divisibleBy60(vector<int> &arr) {
    int sum = 0, even = 0, zero = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        if(arr[i]%2 == 0)
            even++;
        if(arr[i] == 0)
            zero++;
    }
    
    return zero == arr.size() || (sum%3==0 && zero && even>1);
}
