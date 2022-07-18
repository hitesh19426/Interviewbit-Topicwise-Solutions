int count_subarray_with_atmostk_distinct_integer(vector<int>& arr, int k){
    int start = 0, end =0 , n = arr.size(), count = 0;
    unordered_map<int, int> umap;
    while(end < n){
        umap[arr[end]]++;

        while(umap.size()>k && start<=end){
            umap[arr[start]]--;
            if(umap[arr[start]] == 0){
                umap.erase(umap.find(arr[start]));
            }
            start++;
        }
        count += end-start;
        end++;
    }
    return count;
}

int Solution::solve(vector<int> &A, int B) {
    return count_subarray_with_atmostk_distinct_integer(A, B) - count_subarray_with_atmostk_distinct_integer(A, B-1);
}
