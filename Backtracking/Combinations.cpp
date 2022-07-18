void dfs(int start, int n, int k, vector<int> curr, vector<vector<int>>& ans){
    if(curr.size() > k || start > n)
        return;
    
    curr.push_back(start);
    if(curr.size() == k){
        ans.push_back(curr);
    }
    
        
    for(int j=start+1; j<=n; j++){
        dfs(j, n, k, curr, ans);
    }
    
    curr.pop_back();
}

vector<vector<int> > Solution::combine(int n, int k) {
    int start = 1;
    vector<int> curr;
    vector<vector<int>> ans;
    for(int i=1; i<=n; i++)
        dfs(i, n, k, curr, ans);
    return ans;
}