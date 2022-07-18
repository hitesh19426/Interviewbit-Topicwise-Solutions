vector<int> Solution::solve(string s) {
    vector<int> count(26, 0), ans;
    for(char c: s)
        count[c-'a']++;
    
    vector<bool> vis(26, false);
    for(char c: s){
        if(!vis[c-'a']){
            ans.push_back(count[c-'a']);
            vis[c-'a'] = true;
        }
    }
    return ans;
}
