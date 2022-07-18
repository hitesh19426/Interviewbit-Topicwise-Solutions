const int WHITE = -1, GREY = 0, BLACK = 1;

bool dfs(int src, vector<int>& colors, vector<vector<int>>& graph){
    colors[src] = GREY;
    for(int v: graph[src]){
        if(colors[v] == GREY)
            return true;
        if(colors[v] == WHITE && dfs(v, colors, graph))
            return true;
    }
    colors[src] = BLACK;
    return false;
}

int Solution::solve(int n, vector<int> &pre, vector<int> &post) {
    vector<vector<int>> graph(n+1, vector<int>());

    for(int i=0; i<pre.size(); i++){
        graph[pre[i]].push_back(post[i]);
    }

    vector<int> colors(n+1, WHITE);
    for(int i=0; i<=n; i++){
        if(colors[i] == WHITE && dfs(i, colors, graph))
            return false;
    }
    return true;
}
