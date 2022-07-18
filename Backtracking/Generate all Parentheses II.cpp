void helper(int open, int close, int n, string curr, vector<string>& ans){
    if(open > n || close > open)
        return;
    if(curr.size() == 2*n){
        ans.push_back(curr);
        return;
    }
    
    helper(open+1, close, n, curr+'(', ans);
    helper(open, close+1, n, curr+')', ans);
}

vector<string> Solution::generateParenthesis(int n) {
    int open = 0, close = 0, ind = 0;
    string curr = "";
    vector<string> ans;
    helper(open, close, n, curr, ans);
    return ans;
}
