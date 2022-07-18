void extendSubset(vector<int>& arr, int start, vector<int>& current_subset, vector<vector<int>>& all_subsets){
    all_subsets.push_back(current_subset);
    for(int i = start; i<arr.size(); i++){
        if(i != start and arr[i] == arr[i-1])
            continue;
        current_subset.push_back(arr[i]);
        extendSubset(arr, i+1, current_subset, all_subsets);
        current_subset.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> all_subsets;
    vector<int> current_subset;
    extendSubset(A, 0, current_subset, all_subsets);
    return all_subsets;
}
