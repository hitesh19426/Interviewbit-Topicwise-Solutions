int dfs(vector<vector<int>>& tree, int root, int &ans){
    int total_count = 1;
    for(int v:tree[root]){
        int count = dfs(tree, v, ans);
        total_count += count;
        if(count%2==0)
            ans++;
    }
    return total_count;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> tree(A+1, vector<int>());
    for(int i=0; i<B.size(); i++){
        tree[B[i][0]].push_back(B[i][1]);
    }

    int ans = 0;
    dfs(tree, 1, ans);
    return ans;
}
