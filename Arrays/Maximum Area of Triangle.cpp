int getColor(char c){
    return (c == 'r' ? 0 : c == 'b' ? 1 : 2);
}

int Solution::solve(vector<string> &grid) {
    int row = grid.size(), col = grid[0].size();

    vector<int> max_col(3, -1), min_col(3, INT_MAX);
    vector<vector<int>> max_row(3, vector<int>(col, -1)), min_row(3, vector<int>(col, INT_MAX));
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            int color = getColor(grid[i][j]);
            max_col[color] = max(j, max_col[color]);
            min_col[color] = min(j, min_col[color]);
            max_row[color][j] = max(i, max_row[color][j]);
            min_row[color][j] = min(i, min_row[color][j]);
        }
    }

    double ans = 0;
    for(int i=0; i<col; i++){
        for(int color1=0; color1<3; color1++){
            for(int color2=0; color2<3; color2++){
                if(color1 == color2)
                    continue;
                int color3 = 3-color1-color2;

                double x = min_row[color1][i];
                double y = max_row[color2][i];
                double z1 = max_col[color3];
                double z2 = min_col[color3];

                if(y <= x || (z1 <= x && x <= z2))
                    continue;
                
                double base = (y-x+1);
                double height = max(z1-i, i-z2)+1;

                ans = max(ans, base*height/2.0);
            }
        }
    }

    return ceil(ans);
}
