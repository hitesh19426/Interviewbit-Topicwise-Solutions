bool is_inside_circle(int xo, int yo, int r, int x, int y){
    int dist = (xo-x)*(xo-x) + (yo-y)*(yo-y);
    return dist <= r*r;
}

bool inside_any_circle(vector<int>& xi, vector<int>& yi, int r, int x, int y){
    for(int k=0; k<xi.size(); k++){
        if(is_inside_circle(xi[k], yi[k], r, x, y))
            return true;
    }
    return false;
}

bool isvalid(int i, int j, int m, int n){
    return i>=0 && j>=0 && i<=m && j<=n;
}

string Solution::solve(int x, int y, int n, int r, vector<int> &xi, vector<int> &yi){
    if(inside_any_circle(xi, yi, r, 0, 0))
        return "NO";
    
    vector<vector<bool>> vis(x+1, vector<bool>(y+1, false));
    
    queue<pair<int, int>> queue;
    queue.push({0, 0});

    int dx[] = {1, 0, -1, 0, -1, 1, -1, 1};
    int dy[] = {0, -1, 0, 1, -1, 1, 1, -1};

    while(!queue.empty()){
        auto pt = queue.front();
        queue.pop();

        if(pt.first == x && pt.second == y)
            return "YES";

        for(int i=0; i<8; i++){
            int newx = pt.first + dx[i], newy = pt.second + dy[i];
            if(!isvalid(newx, newy, x, y) || vis[newx][newy] || inside_any_circle(xi, yi, r, newx, newy)){
                continue;
            }
            queue.push({newx, newy});
            vis[newx][newy] = true;
        }
    }

    return "NO";
}