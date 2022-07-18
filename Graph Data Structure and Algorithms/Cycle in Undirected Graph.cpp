bool dfs(int src, vector<bool>& vis, vector<vector<int>>& graph, int parent){
    vis[src] = true;
    for(int v: graph[src]){
        if(v == parent)
            continue;
        if(vis[v] || dfs(v, vis, graph, src))
            return true;
    }
    return false;
}

int Solution::solve(int n, vector<vector<int> > &edges) {
    vector<vector<int>> graph(n+1, vector<int>());

    for(auto e: edges){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vector<bool> vis(n+1, false);
    for(int i=0; i<=n; i++){
        if(!vis[i] && dfs(i, vis, graph, -1))
            return true;
    }
    return false;
}
