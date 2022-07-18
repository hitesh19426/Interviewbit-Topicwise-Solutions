vector<int> bfs(vector<vector<int>>& tree, int src){
    int n = tree.size();
    vector<int> dist(n, 0);
    vector<bool> vis(n, false);
    
    queue<int> queue;
    queue.push(src);
    vis[src] = true;

    while(not queue.empty()){
        auto front = queue.front();
        queue.pop();

        for(int v: tree[front]){
            if(!vis[v]){
                queue.push(v);
                dist[v] = dist[front]+1;
                vis[v] = true;
            }
        }
    }

    return dist;
}

int Solution::solve(vector<int> &parent) {
    int n = parent.size();
    vector<vector<int>> tree(n, vector<int>());

    int root = -1;
    for(int i=0; i<parent.size(); i++){
        if(parent[i] == -1){
            root = i;
            continue;
        }
        tree[parent[i]].push_back(i);
        tree[i].push_back(parent[i]);
    }

    auto dist = bfs(tree, root);
    int ind = max_element(dist.begin(), dist.end()) - dist.begin();

    dist = bfs(tree, ind);
    return *max_element(dist.begin(), dist.end());
}
