vector<vector<int> > Solution::solve(vector<int> &arr, int b, int c) {
    vector<vector<int>> matrix(b, vector<int>(c, 0));
    int row_start = 0, row_end = b-1, col_start = 0, col_end = c-1, k = 0;
    
    while(row_start <= row_end || col_start <= col_end){
        if(row_start <= row_end){
            for(int i=col_start; i<=col_end; i++){
                matrix[row_start][i] = arr[k++];
            }
        }

        if(col_start <= col_end){
            for(int i=row_start+1; i<row_end; i++){
                matrix[i][col_end] = arr[k++];
            }
        }

        if(row_start < row_end){
            for(int i=col_end; i>=col_start; i--){
                matrix[row_end][i] = arr[k++];
            }
        }

        if(col_start < col_end){
            for(int i=row_end-1; i>row_start; i--){
                matrix[i][col_start] = arr[k++];
            }
        }

        row_start++, row_end--, col_start++, col_end--;
    }

    return matrix;
}
