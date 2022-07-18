void helper(int ind, int n, vector<string>& curr, vector<vector<string>>& ans, vector<int>& col, vector<int>& anti, vector<int>& diag){
    if(ind == n){
        ans.push_back(curr);
        return;
    }

    for(int i=0; i<n; i++){
        if(col[i] || anti[i-ind+n] || diag[ind+i])
            continue;
        col[i] = anti[i-ind+n] = diag[ind+i] = true;
        curr[ind][i] = 'Q';
        helper(ind+1, n, curr, ans, col, anti, diag);
        col[i] = anti[i-ind+n] = diag[ind+i] = false;
        curr[ind][i] = '.';
    }
}
vector<vector<string> > Solution::solveNQueens(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> col(n, false), anti(2*n, false), diag(2*n, false);
    vector<vector<string>> ans;
    vector<string> curr(n, string(n, '.'));
    helper(0, n, curr, ans, col, anti, diag);
    return ans;
}
