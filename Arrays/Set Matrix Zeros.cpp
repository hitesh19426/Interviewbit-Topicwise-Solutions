void Solution::setZeroes(vector<vector<int>> &matrix) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool row = false, col = false;
    int m = matrix.size(), n = matrix[0].size();

    for(int i=0; i<m; i++){
        if(matrix[i][0] == 0)
            col = true;
    }
    for(int i=0; i<n; i++){
        if(matrix[0][i] == 0)
            row = true;
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if(row){
        for(int j=0; j<n; j++) matrix[0][j] = 0;
    }
    if(col){
        for(int i=0; i<m; i++) matrix[i][0] = 0;
    }
}
