bool isvalid(int m, int n, int i, int j){
    return i>=0 && j>=0 && i<m && j<n;
}

bool dfs(vector<string>& grid, string& word, int ind, int i, int j){
    int m = grid.size(), n = grid[0].size();
    if(!isvalid(m, n, i, j) || grid[i][j] != word[ind])
        return false;
    if(ind == word.size()-1){
        return true;
    }

    bool ans = false;
    int dir[] = {1, 0, -1, 0, 1};
    for(int k=0; k<4; k++){
        ans |= dfs(grid, word, ind+1, i+dir[k], j+dir[k+1]);
    }

    return ans;
}

int Solution::exist(vector<string> &grid, string word) {
    int m = grid.size(), n = grid[0].size();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == word[0] && dfs(grid, word, 0, i, j))
                return true;
        }
    }

    return false;
}
