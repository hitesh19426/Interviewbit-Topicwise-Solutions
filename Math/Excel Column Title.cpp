string Solution::convertToTitle(int n) {
    string ans = "";
    while(n){
        int digit = (n-1)%26;        
        n = (n-1)/26;
        ans += (digit + 'A');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
