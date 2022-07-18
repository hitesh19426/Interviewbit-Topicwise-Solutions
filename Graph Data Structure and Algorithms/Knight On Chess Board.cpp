int Solution::knight(int m, int n, int x, int y, int a, int b) {
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    
    queue<pair<int, int>> queue;
    queue.push({x-1, y-1});
    dist[x-1][y-1] = 0;

    int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
    int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

    while(!queue.empty()){
        auto pt = queue.front();
        queue.pop();

        if(pt.first == a-1 && pt.second == b-1)
            return dist[pt.first][pt.second];

        for(int k=0; k<8; k++){
            int newx = pt.first + dx[k], newy = pt.second+dy[k];
            if(newx<0 || newy<0 || newx>=m || newy>=n)
                continue;
            if(dist[newx][newy] == INT_MAX){
                dist[newx][newy] = dist[pt.first][pt.second] + 1;
                queue.push({newx, newy});
            }
        }
    }

    return -1;
    // return dist[a-1][b-1];
}