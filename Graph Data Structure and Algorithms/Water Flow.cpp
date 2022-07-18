bool isvalid(int m , int n, int i, int j){
    return i>=0 && j>=0 && i<m && j<n;
}

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row, int col, bool bluelake){
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> queue;
    for(int i=0; i<m; i++){
        queue.push({i, col});
        vis[i][col] = true;
    }
    for(int i=0; i<n; i++){
        queue.push({row, i});
        vis[row][i] = true;
    }

    int dir[] = {1, 0, -1, 0, 1};

    while(!queue.empty()){
        auto front = queue.front();
        queue.pop();

        int i = front.first, j = front.second;

        for(int k=0; k<4; k++){
            int newi = i + dir[k], newj = j + dir[k+1];
            if(isvalid(m, n, newi, newj) && !vis[newi][newj] && grid[newi][newj] >= grid[i][j]){
                queue.push({newi, newj});
                vis[newi][newj] = true;
            }
        }
    }
}

int Solution::solve(vector<vector<int> > &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> is_blue_reachable(m, vector<bool>(n, false));
    vector<vector<bool>> is_red_reachable(m, vector<bool>(n, false));

    bfs(grid, is_blue_reachable, 0, 0, true);
    bfs(grid, is_red_reachable, m-1, n-1, false);

    int count = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(is_blue_reachable[i][j] && is_red_reachable[i][j])
                count++;
        }
    }

    return count;
}
