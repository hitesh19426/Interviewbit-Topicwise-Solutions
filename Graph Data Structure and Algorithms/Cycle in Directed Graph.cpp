int GREY = 0, BLACK = -1, WHITE = 1;

bool detectCycle(int src, vector<int>& color, vector<vector<int>>& graph){
    color[src] = GREY;
    for(int v: graph[src]){
        if(color[v] == GREY)
            return true;
        if(color[v] == WHITE && detectCycle(v, color, graph))
            return true;
    }

    color[src] = BLACK;
    return false;
}

int Solution::solve(int n, vector<vector<int> > &edges) {
    vector<vector<int>> graph(n+1, vector<int>());

    for(auto edge: edges){
        graph[edge[0]].push_back(edge[1]);
    }

    vector<int> color(n+1, WHITE);
    for(int i=0; i<=n; i++){
        if(color[i] == WHITE && detectCycle(i, color, graph))
            return true;
    }

    return false;
}
