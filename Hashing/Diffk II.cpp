int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_set<int> seen;
    for(int i=0; i<A.size(); i++){
        if(seen.find(A[i]+B) != seen.end())
            return true;
        else if(seen.find(A[i]-B) != seen.end())
            return true;
        else
            seen.insert(A[i]);
    }

    return false;
}
