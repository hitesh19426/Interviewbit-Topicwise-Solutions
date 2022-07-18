string Solution::multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    vector<int> sum(m+n, 0);
    
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            sum[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
            sum[i+j] += sum[i+j+1]/10;
            sum[i+j+1] %= 10;
        }
    }

    int ind = 0;
    while(ind < sum.size()-1 && sum[ind] == 0)
        ind++;
    
    string ans = "";
    while(ind < sum.size())
        ans += '0' + sum[ind++];
    return ans;
}
