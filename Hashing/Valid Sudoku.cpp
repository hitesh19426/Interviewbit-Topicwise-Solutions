int Solution::isValidSudoku(const vector<string> &A) {
    bool row[9][9], col[9][9], box[3][3][9];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(box, 0, sizeof(box));

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(A[i][j] == '.')
                continue;
            int ind = A[i][j]-'1';
            if(row[i][ind] || col[j][ind] || box[i/3][j/3][ind])
                return false;
            
            row[i][ind] = true;
            col[j][ind] = true;
            box[i/3][j/3][ind] = true;
        }
    }

    return true;
}
