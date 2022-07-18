int binary_search(vector<int>& arr, int low, int target){
    int high = arr.size()-1, index = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > target)
            index = mid, low = mid+1;
        else
            high = mid-1;
    }
    return index;
}

bool next_permutation(vector<int>& arr){
    int i = arr.size();
    while(i>0 && arr[i] <= arr[i-1])
        i--;
    if(i == 0)
        return false;

    int index = binary_search(arr, i, arr[i-1]);
    swap(arr[i-1], arr[index]);
    reverse(arr.begin()+i, arr.end());
    return true;
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> permutations;
    sort(A.begin(), A.end());
    do{
        permutations.push_back(A);
    }while(next_permutation(A));

    return permutations;
}
