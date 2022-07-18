vector<int> Solution::solve(vector<int> &arr) {
    int insert_index = 0;
    for(int x: arr){
        if(x){
            swap(x, arr[insert_index++]);
        }
    }
    return arr;
}
