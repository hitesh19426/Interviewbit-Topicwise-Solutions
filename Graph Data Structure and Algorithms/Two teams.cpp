int WHITE = -1, RED = 1;

bool dfs(vector<vector<int>>& graph, vector<int>& colors, int src, int color){
    colors[src] = color;
    for(int v: graph[src]){
        if(colors[v] == color)
            return false;
        if(colors[v] == WHITE)
            dfs(graph, colors, v, 1-color);
    }
    return true;
}

int Solution::solve(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n+1, vector<int>());
    for(auto edge: edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<int> colors(n+1, WHITE);
    for(int i=1; i<=n; i++){
        if(colors[i] == WHITE && !dfs(graph, colors, i, RED))
            return false;
    }
    return true;
}
