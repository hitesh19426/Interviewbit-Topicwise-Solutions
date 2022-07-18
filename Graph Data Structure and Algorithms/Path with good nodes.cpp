void dfs(vector<vector<int>>& graph, vector<int> &good, int src, int C, int &count, int& ans, int parent){
    if(good[src-1] == 1)
        count++;
    if(graph[src].size()==1u && count <= C)
        ans++;

    for(int v: graph[src]){
        if(parent != v)
            dfs(graph, good, v, C, count, ans, src);
    }

    if(good[src-1] == 1)
        count--;
}

int Solution::solve(vector<int> &good, vector<vector<int> >& edges, int C) {
    int n = good.size();
    vector<vector<int>> graph(n+1, vector<int>());

    for(auto &edge: edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    int count = 0, ans = 0, src = 1, parent = -1;
    dfs(graph, good, src, C, count, ans, parent);
    return ans;
}
