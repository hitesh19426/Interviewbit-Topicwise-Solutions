vector<int> Solution::solve(vector<int> &arr, int k) {
    nth_element(arr.begin(), arr.begin()+k, arr.end(), greater<int>());
    
    vector<int> ans;
    for(int i=0; i<k; i++)
        ans.push_back(arr[i]);
    return ans;
}
