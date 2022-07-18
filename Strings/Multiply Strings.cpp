string multiply2(string& a, int b){
    string ans = "";
    int carry = 0;
    for(int i=a.size()-1; i>=0; i--){
        int digit = a[i] - '0';
        ans += to_string( (digit*b + carry)%10);
        carry = (digit*b+carry)/10;
    }
    if(carry){
        ans += to_string(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string add(string& a, string &b){
    int i = a.size()-1, j = b.size()-1, carry = 0;
    string ans = "";
    while(i>=0 || j>=0){
        int x = (i>=0 ? a[i]-'0' : 0);
        int y = (j>=0 ? b[j]-'0' : 0);

        ans += to_string((x+y+carry)%10);
        carry = (x+y+carry)/10;

        if(i>=0) i--;
        if(j>=0) j--;
    }
    if(carry)
        ans += to_string(carry);
    reverse(ans.begin(), ans.end());
    return ans;
}


string Solution::multiply(string A, string B) {
    if(A.size()<B.size())
        return multiply(B, A);

    int count = 0;
    string ans = "";
    for(int i=B.size()-1; i>=0; i--, count++){
        int digit = B[i]-'0';
        string res = multiply2(A, digit);
        for(int j=0; j<count; j++)
            res += '0';
        ans = add(ans, res);
    }
    int i=0;
    while(i<ans.size() && ans[i] == '0')
        i++;
    ans  = ans.substr(i);
    return ans == "" ? "0" : ans;
}
