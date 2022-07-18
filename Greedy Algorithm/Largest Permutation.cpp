vector<int> Solution::solve(vector<int> &arr, int k) {
    unordered_map<int, int> position;
    for(int i=0; i<arr.size(); i++){
        position[arr[i]] = i;
    }

    int n = arr.size(), target = n;
    for(int i=0; i<arr.size(); i++){
        if(k==0)
            break;
        if(arr[i] != target){
            position[arr[i]] = position[target];
            swap(arr[i], arr[position[target]]);
            k--;
        }
        target--;
    }

    return arr;
}
