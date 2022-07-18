vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n = A.size(), m = A[0].size();
    vector<int> ans;
    vector<vector<int>> dist(n+2, vector<int>(m+2, 1e8));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(A[i-1][j-1] == 1){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = min(min(dist[i-1][j]+1, dist[i][j-1]+1), dist[i][j]);
            }
        }
    }

    for(int i=n; i>=1; i--){
        for(int j=m; j>=1; j--){
            if(A[i-1][j-1] == 1){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = min(min(dist[i+1][j]+1, dist[i][j+1]+1), dist[i][j]) ;
            }
        }
    }

    for(auto &query: B){
        ans.push_back(dist[query[0]][query[1]]);
    }

    return ans;
}
