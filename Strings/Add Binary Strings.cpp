string Solution::addBinary(string A, string B) {
    int i = A.size()-1, j = B.size()-1, carry = 0;
    string ans;
    while(i>=0 || j>=0){
        int x = (i>=0 ? A[i]-'0' : 0);
        int y = (j>=0 ? B[j]-'0' : 0);

        ans += to_string((x+y+carry)%2);
        carry = (x+y+carry)/2;

        if(i>=0) i--;
        if(j>=0) j--;
    }
    if(carry)
        ans += '1';

    reverse(ans.begin(), ans.end());
    return ans;
}
