vector<vector<string>> dp;
vector<string> helper(int i, string &s, set<string>& dict){
    if(i<0)
        return {};
    if(not dp[i].empty())
        return dp[i];
    
    vector<string> ans;
    if(dict.find(s.substr(0, i+1)) != dict.end())
        ans.push_back(s.substr(0, i+1));
    
    for(int j=0; j<i; j++){
        auto word = s.substr(j+1, i-j);
        if(dict.find(word) != dict.end()){
            auto prefix = helper(j, s, dict);
            for(auto &p: prefix)
                ans.push_back(p + " " + word);
        }
    }
    
    return dp[i] = ans;
}

vector<string> Solution::wordBreak(string s, vector<string>& wordDict) {
    set<string> dict(wordDict.begin(), wordDict.end());
    dp.assign(51, vector<string>());
    auto ans = helper(s.size()-1, s, dict);
    sort(ans.begin(), ans.end());
    return ans;
}
