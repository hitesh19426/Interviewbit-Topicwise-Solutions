vector<int> Solution::addArrays(vector<int> &a, vector<int> &b){
    if(a.size() < b.size())
        return addArrays(b, a);
    
    int carry = 0, i  = a.size()-1, j = b.size()-1;
    while(j>=0){
        int sum = a[i]+b[j]+carry;
        a[i] = sum%10;
        carry = sum/10;

        i--, j--;
    }
    while(i>=0){
        int sum = a[i]+carry;
        a[i] = sum%10;
        carry = sum/10;
        i--;
    }
    if(carry)
        a.insert(a.begin(), 1);
        
    return a;
}