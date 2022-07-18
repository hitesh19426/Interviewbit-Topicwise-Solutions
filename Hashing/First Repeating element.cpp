int Solution::solve(vector<int> &A) {
    unordered_map<int, int> umap;
    for(int i=0; i<A.size(); i++){
        umap[A[i]]++;
    }

    for(int i=0; i<A.size(); i++){
        if(umap[A[i]] > 1)
            return A[i];
    }
    return -1;
}
