vector<vector<int>> merge(vector<vector<int>>& a, vector<vector<int>>& b){
    vector<vector<int>> ans;
    int i = 0, j = 0;
    while(i<a.size() && j<b.size()){
        if(a[i] == b[j])
            i++;
        else if(a[i] < b[j])
            ans.push_back(a[i++]);
        else
            ans.push_back(b[j++]);
    }
    while(i<a.size())
        ans.push_back(a[i++]);
    while(j<b.size())
        ans.push_back(b[j++]);
    
    return ans;
}

vector<vector<int>> helper(vector<int>& arr, int i, int target){
    if(i<0){
        if(target == 0)
            return {{}};
        return {};
    }

    auto withi = helper(arr, i-1, target - arr[i]);
    auto withouti = helper(arr, i-1, target);

    for(auto &comb: withi)
        comb.push_back(arr[i]);
    return merge(withi, withouti);
}

vector<vector<int> > Solution::combinationSum(vector<int> &arr, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(arr.begin(), arr.end());
    return helper(arr, arr.size()-1, target);
}
