int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> umap;
    int odd = 0, count = 0;
    for(int i=0; i<A.size(); i++){
        if(A[i]&1)
            odd++;
        if(odd == B)
            count++;
        if(odd >= B)
            count += umap[odd-B];
        umap[odd]++;
    }
    return count;
}
