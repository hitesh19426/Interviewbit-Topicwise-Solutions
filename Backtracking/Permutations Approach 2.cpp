vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> permutations;
    sort(A.begin(), A.end());
    do{
        permutations.push_back(A);
    }while(next_permutation(A.begin(), A.end()));

    return permutations;
}