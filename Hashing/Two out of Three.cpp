vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_set<int> b, c, a;
    for(auto x:B)
        b.insert(x);
    for(auto x:C)
        c.insert(x);
    for(auto x:A)
        a.insert(x);

    set<int> set;
    for(auto x: A){
        if(b.find(x) != b.end() || c.find(x) != c.end())
            set.insert(x);
    }
    for(auto x: B){
        if(a.find(x) != a.end() || c.find(x) != c.end())
            set.insert(x);
    }
    
    vector<int> ans;
    for(auto x: set)
        ans.push_back(x);
    return ans;
}
