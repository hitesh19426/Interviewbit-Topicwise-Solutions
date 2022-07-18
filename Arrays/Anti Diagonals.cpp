vector<vector<int> > Solution::diagonal(vector<vector<int> > &arr) {
    vector<vector<int>> ans;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int x = 0, y = i;
        vector<int> row;
        while(x<n && y>=0){
            row.push_back(arr[x][y]);
            x++, y--;
        }
        ans.push_back(row);
    }

    for(int i=1; i<n; i++){
        int x = i, y = n-1;
        vector<int> row;
        while(x<n && y>=0){
            row.push_back(arr[x][y]);
            x++, y--;
        }
        ans.push_back(row);
    }

    return ans;
}
