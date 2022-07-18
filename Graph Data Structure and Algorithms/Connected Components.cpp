void dfs(int u, vector<bool>& vis, vector<vector<int>>& graph){
    vis[u] = true;
    for(int v: graph[u]){
        if(!vis[v])
            dfs(v, vis, graph);
    }
}

int Solution::solve(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n+1, vector<int>());

    for(auto &e:edges){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    vector<bool> vis(n+1, false);

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, vis, graph);
            ans++;
        }
    }

    return ans;
}
