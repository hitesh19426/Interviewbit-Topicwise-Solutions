vector<int> dp;
bool helper(string &s, int ind, unordered_set<string>& dict){
    if(ind == (int)s.size())
        return true;
    if(dp[ind] != -1)
        return dp[ind];
    
    string word = "";
    for(int j=ind; j<s.size(); j++){
        word += s[j];
        if(dict.find(word) != dict.end() && helper(s, j+1, dict))
            return dp[ind] = true;
    }
    
    return dp[ind] = false;
}
    
int Solution::wordBreak(string s, vector<string> &wordDict) {
    dp.assign(s.size(), -1);
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return helper(s, 0, dict);
}
