int dfs(vector<vector<int>>& grid, int i, int j){
    int m = grid.size(), n = grid[0].size();
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0)
        return 0;

    grid[i][j] = 0;
    int ans = 1;
    int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
    int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

    for(int k=0; k<8; k++){
        ans += dfs(grid, i+dx[k], j+dy[k]);
    }

    return ans;
}

int Solution::solve(vector<vector<int> > &grid) {
    int m = grid.size(), n = grid[0].size();

    int ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1)
                ans = max(ans, dfs(grid, i, j));
        }
    }

    return ans;
}
