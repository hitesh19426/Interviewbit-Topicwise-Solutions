void dfs(int i, int j, vector<string>& grid){
    int m  = grid.size(), n = grid[0].size();
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 'O')
        return;
    
    grid[i][j] = 'O';

    int dir[] = {1, 0, -1, 0, 1};
    for(int k=0; k<4; k++){
        dfs(i+dir[k], j+dir[k+1], grid);
    }
}

int Solution::black(vector<string> &grid) {
    int m  = grid.size(), n = grid[0].size(), ans = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 'X'){
                dfs(i, j, grid);
                ans++;
            }
        }
    }

    return ans;
}
