long long dijkstra(int start, int end, int n, vector<vector<pair<int, int>>>& graph){
    vector<long long> dist(n+1, LLONG_MAX);
    set<pair<long long, int>> minheap;
    
    dist[start] = 0;
    minheap.insert({0, start});
    
    while(!minheap.empty()){
        auto [d, node] = *minheap.begin();
        minheap.erase(minheap.begin());
        
        for(auto& [v, len]: graph[node]){
            if(d != LLONG_MAX && dist[v] > d + len){
                minheap.erase({dist[v], v});
                dist[v] = d+len;
                minheap.insert({dist[v], v});
            }
        }
    }
    
    return dist[end];
}

int Solution::solve(int n, vector<vector<int>>& edges, int start, int end, vector<vector<int>>& extra) {
    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>());
    for(auto& edge: edges){
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
    }
    
    long long res = LLONG_MAX;
    for(auto& edge: extra){
        if(edge[1] > n || edge[0] > n)
            continue;
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
        
        res = min(res, dijkstra(start, end, n, graph));
        
        graph[edge[0]].pop_back();
        graph[edge[1]].pop_back();
    }
    
    return (res == LLONG_MAX ? -1 : (int)res);
}
