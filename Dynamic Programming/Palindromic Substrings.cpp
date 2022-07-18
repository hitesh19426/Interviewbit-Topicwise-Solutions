int expandAroundCenter(string &s, int low, int high, int count = 0){
    while(low>=0 && high<s.size() && s[low] == s[high])
        low--, high++, count++;
    return count;
}

int Solution::solve(string s) {
    int ans = 0;
        
    for(int i=0; i<s.size(); i++){
        ans += expandAroundCenter(s, i, i);
        ans += expandAroundCenter(s, i, i+1);
    }
    
    return ans;
}
