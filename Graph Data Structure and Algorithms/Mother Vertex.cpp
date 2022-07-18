void dfs(int u, vector<bool>& vis, vector<vector<int>>& graph){
    vis[u] = true;
    for(int v: graph[u]){
        if(!vis[v])
            dfs(v, vis, graph);
    }
}

int Solution::motherVertex(int n, vector<vector<int>> &edges){
    vector<vector<int>> graph(n+1, vector<int>());

    for (auto e: edges){
        graph[e[0]].push_back(e[1]);
    }

    int mother = 0;
    vector<bool> vis(n+1, false);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, vis, graph);
            mother = i;
        }
    }

    vis.assign(n+1, false);
    dfs(mother, vis, graph);
    for(int i=1; i<=n; i++){
        if(vis[i] == false)
            return false;
    }
    
    return true;
}