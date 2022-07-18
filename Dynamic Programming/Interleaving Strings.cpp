int m, n, p;
vector<vector<int>> dp;
bool helper(string &s1, int i, string& s2, int j, string& s3, int k){
    if(i == 0 && j == 0 && k == 0)
        return true;
    if((i == 0 && j == 0) || k == 0)
        return false;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(i == 0)
        return dp[i][j] = (s2[j-1] == s3[k-1] && helper(s1,i,s2,j-1,s3,k-1));
    if(j == 0)
        return dp[i][j] = (s1[i-1] == s3[k-1] && helper(s1,i-1,s2,j,s3,k-1));
    if(s1[i-1] == s3[k-1] || s2[j-1] == s3[k-1])
        return dp[i][j] = (s1[i-1] == s3[k-1] && helper(s1,i-1,s2,j,s3,k-1)) || (s2[j-1] == s3[k-1] && helper(s1,i,s2,j-1,s3,k-1));
    return dp[i][j] = false;
}
    
int Solution::isInterleave(string s1, string s2, string s3) {
    m = s1.size(), n = s2.size(), p = s3.size();
    dp.assign(s1.size()+1, vector<int>(s2.size()+1, -1));
    return helper(s1, m, s2, n, s3, p);
}
