int Solution::solve(vector<int> &A, int B) {
    int index = upper_bound(A.begin(), A.end(), B) - A.begin();

    return index;
}
