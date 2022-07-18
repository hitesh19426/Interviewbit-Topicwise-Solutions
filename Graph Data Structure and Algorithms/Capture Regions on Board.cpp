bool isvalid(int i, int j, int m, int n){
    return i>=0 && j>=0 && i<m && j<n;
}

void dfs(vector<vector<char>>& grid, int i, int j){
    int m = grid.size(), n = grid[0].size();
    if(!isvalid(i, j, m, n) || grid[i][j] == 'X' || grid[i][j] == '.')
        return;

    grid[i][j] = '.';

    int dir[] = {1, 0, -1, 0, 1};
    for(int k=0; k<4; k++){
        dfs(grid, i+dir[k], j+dir[k+1]);
    }
}

void Solution::solve(vector<vector<char> > &grid) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, insteadint m = grid.size(), n = grid[0].size(); return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 'O'){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    dfs(grid, i, j);
                }
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '.')
                grid[i][j] = 'O';
            else if(grid[i][j] == 'O')
                grid[i][j] = 'X';
        }
    }
}
