vector<int> Solution::getRow(int n) {
    vector<int> ans{{1}};
    for(int i=1; i<=n; i++){
        vector<int> temp{1};
        for(int j=1; j<i; j++)
            temp.push_back(ans[j-1] + ans[j]);
        temp.push_back(1);
        ans = temp;
    }
    return ans;
}
