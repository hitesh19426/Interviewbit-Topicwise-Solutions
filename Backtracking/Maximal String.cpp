string Solution::solve(string A, int B) {
    if(B == 0)
        return A;
    string ans = A;
    for(int i=0; i<A.size(); i++){
        for(int j=i+1; j<A.size(); j++){
            if(A[j] > A[i]){
                string copy = A;
                swap(copy[i], copy[j]);
                copy = solve(copy, B-1);
                ans = max(ans, copy);
            }
        }
    }
    return ans;
}
