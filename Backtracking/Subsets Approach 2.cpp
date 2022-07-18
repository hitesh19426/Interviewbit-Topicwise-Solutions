vector<vector<int>> generateSubsets(vector<int>& arr, int n){
    if(n == 1){
        return {{}, {arr[0]}};
    }

    vector<vector<int>> ans;
    auto without_last = generateSubsets(arr, n-1);
    for(auto subset: without_last){
        ans.push_back(subset);
        subset.push_back(arr[n-1]);
        ans.push_back(subset);
    }
    return ans;
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    if(A.empty())
        return {{}};
    auto ans = generateSubsets(A, A.size());
    sort(ans.begin(), ans.end());
    return ans;
}