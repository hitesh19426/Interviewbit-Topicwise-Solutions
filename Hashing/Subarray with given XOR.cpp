int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> umap;
    int value = 0, count = 0;
    for(int i=0; i<A.size(); i++){
        value ^= A[i];
        if(value == B)
            count++;
        count += umap[value^B];
        umap[value]++;
    }
    return count;
}
