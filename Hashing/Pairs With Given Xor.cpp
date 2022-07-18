int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> seen;
    int count = 0;
    for(int i=0; i<A.size(); i++){
        if(seen.find(A[i]^B) != seen.end())
            count += seen[A[i]^B];
        seen[A[i]]++;
    }
    return count;
}
