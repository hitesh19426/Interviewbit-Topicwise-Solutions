bool isvalid(int x, int y, int m, int n){
    return x>=0 && y>=0 && x<m && y<n;
}

int Solution::solve(int row, int col, vector<string> &grid) {
    vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

    deque<pair<int, int>> queue;
    queue.push_back({0, 0});
    dist[0][0] = 0;

    map<char, pair<int, int>> dir;
    dir['U'] = {-1, 0};
    dir['L'] = {0, -1};
    dir['D'] = {1, 0};
    dir['R'] = {0, 1};
    
    while(not queue.empty()){
        auto pt = queue.front();
        queue.pop_front();

        for(char move: {'U', 'L', 'D', 'R'}){
            int newx = pt.first + dir[move].first, newy = pt.second + dir[move].second;
            if(!isvalid(newx, newy, row, col))
                continue;
            
            if(move == grid[pt.first][pt.second] && dist[newx][newy] > dist[pt.first][pt.second]){
                queue.push_front({newx, newy});
                dist[newx][newy] = dist[pt.first][pt.second];
            }
            if(move != grid[pt.first][pt.second] && dist[newx][newy] > dist[pt.first][pt.second]){
                queue.push_back({newx, newy});
                dist[newx][newy] = dist[pt.first][pt.second]+1;
            }
        }
    }

    return dist[row-1][col-1];
}
