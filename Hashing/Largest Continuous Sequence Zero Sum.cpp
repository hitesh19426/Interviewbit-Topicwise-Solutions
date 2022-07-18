vector<int> Solution::lszero(vector<int> &A) {
    int sum = 0, length = 0, start = 0;
    unordered_map<int, int> umap;
    for(int i=0; i<A.size(); i++){
        sum += A[i];
        if(sum == 0){
            length = i+1;
            start = 0;
        }
        if(umap.find(sum) == umap.end()){
            umap[sum] = i;
        }
        else{
            if(i-umap[sum] > length){
                length = i-umap[sum];
                start = umap[sum]+1;
            }
        }
    }

    vector<int> ans;
    while(length--){
        ans.push_back(A[start++]);
    }

    return ans;
}
