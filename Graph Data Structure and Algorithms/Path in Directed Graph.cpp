void dfs(vector<vector<int>>& graph, vector<bool>& vis, int src){
    if(vis[src])
        return;

    vis[src] = true;
    for(int v: graph[src]){
        dfs(graph, vis, v);
    }
}

int Solution::solve(int n, vector<vector<int> > &edges) {
    vector<vector<int>> graph(n+1, vector<int>());
    for(auto edge: edges){
        graph[edge[0]].push_back(edge[1]);
    }

    vector<bool> vis(n+1, false);
    dfs(graph, vis, 1);
    return vis[n];
}
