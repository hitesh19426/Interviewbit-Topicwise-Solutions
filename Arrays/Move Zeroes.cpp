vector<int> Solution::solve(vector<int> &arr) {
    int to_insert = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != 0){
            swap(arr[to_insert++], arr[i]);
        }
    }
    return arr;
}
