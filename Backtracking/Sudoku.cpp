typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;

bool solve(vector<vector<char>>& board, vvb& row, vvb& col, vvvb& box, vector<pair<int,int>>& spaces, int ind){
    if(ind == spaces.size())
        return true;

    for(int i=1; i<=9; i++){
        auto [r, c] = spaces[ind];
        if(row[r][i-1] || col[c][i-1] || box[r/3][c/3][i-1])
            continue;
        board[r][c] = '0'+i;
        row[r][i-1] = col[c][i-1] = box[r/3][c/3][i-1] = true;
        if(solve(board, row, col, box, spaces, ind+1))
            return true;
        board[r][c] = '.';
        row[r][i-1] = col[c][i-1] = box[r/3][c/3][i-1] = false;
    }

    return false;
}

void Solution::solveSudoku(vector<vector<char> > &board) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<pair<int,int>> spaces;
    vvb row(9, vb(9, false)), col(9, vb(9, false));
    vvvb box(3, vvb(3, vb(9, false)));
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.'){
                spaces.push_back({i, j});
            }
            else{
                int ind = board[i][j] - '1';
                row[i][ind] = col[j][ind] = box[i/3][j/3][ind] = true;
            }
        }
    }

    solve(board, row, col, box, spaces, 0);
    // return board;
}
