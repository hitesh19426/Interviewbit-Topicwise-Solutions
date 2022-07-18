vector<int> Solution::solve(vector<int> &arr) {
    int insert_index = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 0){
            swap(arr[insert_index++], arr[i]);
        }
    }
    return arr;
}
