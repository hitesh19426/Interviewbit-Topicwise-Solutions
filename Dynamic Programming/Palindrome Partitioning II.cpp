int Solution::minCut(string s) {
    int n = s.size();
    vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
    for(int l=n-1; l>=0; l--){
        for(int r=l; r<n; r++){
            if(l == r)
                is_palindrome[l][r] = true;
            else if(l+1 == r)
                is_palindrome[l][r] = (s[l] == s[r]);
            else
                is_palindrome[l][r] = (s[l] == s[r] && is_palindrome[l+1][r-1]);
        }
    }
    
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int ind=0; ind<n; ind++){
        if(is_palindrome[0][ind]){
            dp[ind] = 0;
        }
        else{
            for(int j=1; j<=ind; j++){
                if(is_palindrome[j][ind])
                    dp[ind] = min(dp[ind], 1+dp[j-1]);
            }
        }
    }
    
    return dp[n-1];
}
