vector<vector<int> > Solution::solve(int n) {
    if(n == 0)
        return {};
    vector<vector<int>> tri{{1}};
    for(int i=1; i<n; i++){
        vector<int> temp{1};
        for(int j=1; j<i; j++)
            temp.push_back(tri.back()[j-1] + tri.back()[j]);
        temp.push_back(1);
        tri.push_back(temp);
    }

    return tri;
}
