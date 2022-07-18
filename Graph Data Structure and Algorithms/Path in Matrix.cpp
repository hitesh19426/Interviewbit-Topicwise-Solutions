bool dfs(int i, int j, pair<int, int>& dest, vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size();
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0)
        return false;
    if(i == dest.first && j == dest.second)
        return true;

    grid[i][j] = 0;
    int dir[] = {1, 0, -1, 0, 1};
    for(int k=0; k<4; k++){
        if(dfs(i+dir[k], j+dir[k+1], dest, grid))
            return true;
    }
    return false;
}

int Solution::checkPath(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    pair<int, int> src, dest;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1)
                src = {i, j};
            if(grid[i][j] == 2)
                dest = {i, j};
        }
    }

    if(dfs(src.first, src.second, dest, grid))
        return true;
    return false;
}
