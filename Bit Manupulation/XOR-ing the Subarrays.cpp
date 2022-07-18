int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(not (n&1))
        return 0;

    int ans = 0;
    for(int i=0; i<n; i+=2){
        ans ^= A[i];
    }
    return ans;
}
