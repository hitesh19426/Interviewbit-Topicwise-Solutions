int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n = 100;
    vector<vector<int>> graph(n+1, vector<int>());

    vector<int> snakes(n+1, -1);
    vector<int> ladders(n+1, -1);

    for(auto pa: A)
        ladders[pa[0]] = pa[1];
    for(auto pa: B)
        snakes[pa[0]] = pa[1];
    

    for(int i=1; i<=100; i++){
        if(ladders[i] != -1){
            graph[i].push_back(ladders[i]);
        }
        else if(snakes[i] != -1){
            graph[i].push_back(snakes[i]);
        }
        else{
            for(int dx=1; dx<=6; dx++){
                if(i+dx<=100)
                    graph[i].push_back(i+dx);
            }
        }
    }

    vector<int> dist(n+1, INT_MAX);
    queue<int> queue;
    queue.push(1);
    dist[1] = 0;

    while(not queue.empty()){
        auto pt = queue.front();
        queue.pop();

        for(int v: graph[pt]){
            if(dist[v] == INT_MAX){
                queue.push(v);
                if(snakes[pt] != -1 || ladders[pt] != -1)
                    dist[v] = dist[pt];
                else
                    dist[v] = dist[pt]+1;
            }
        }
    }

    if(dist[100] == INT_MAX)
        return -1;
    return dist[100];
}
