int Solution::solve(vector<int> &arr) {
    int max_so_far = INT_MIN, count = 0;
    for(int i=0; i<arr.size(); i++){
        if(max_so_far < arr[i])
            count++;
        max_so_far = max(max_so_far, arr[i]);
    }
    return count;
}
