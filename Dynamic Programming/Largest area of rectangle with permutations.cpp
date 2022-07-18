int Solution::solve(vector<vector<int> > &arr) {
    int m = arr.size(), n = arr[0].size();
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1){
                arr[i][j] += arr[i-1][j];
            }
        }
    }

    int ans = 0;
    for(auto &row: arr){
        sort(row.begin(), row.end(), greater<int>());
        int high = 0;
        while(high < n){
            ans = max(ans, (high+1)*row[high]);
            high++;
        }
    }

    return ans;
}
