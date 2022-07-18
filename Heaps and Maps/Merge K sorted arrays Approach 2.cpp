vector<int> merge(vector<int>& a, vector<int>& b){
    if(a.empty() || b.empty())
        return a.empty() ? b : a;
    
    vector<int> ans;
    int i = 0, j = 0;
    while(i<a.size() && j<b.size()){
        if(a[i] < b[j])
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
vector<int> mergeSort(vector<vector<int>>& arr, int low, int high){
    if(low > high)
        return {};
    if( low == high)
        return arr[low];
    int mid = low + (high-low)/2;

    auto left = mergeSort(arr, low, mid);
    auto right = mergeSort(arr, mid+1, high);
    return merge(left, right);
}
vector<int> Solution::solve(vector<vector<int> > &A) {
    return mergeSort(A, 0, A.size()-1);
}