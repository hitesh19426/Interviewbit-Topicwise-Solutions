int Solution::setIntersection(vector<vector<int>> &arr) {
    sort(arr.begin(), arr.end(), [](auto &a, auto &b) -> bool {
        if(a[1] != b[1])
            return a[1] < b[1];
        return a[0] > b[0];
    });
    
    int endpoint0 = arr[0][1]-1, endpoint1 = arr[0][1], count = 2;
    // cout << endpoint0 << " " << endpoint1 << endl;
    for(int i=1; i<arr.size(); i++){
        if(arr[i][0] <=  endpoint0){
            continue;
        }
        if(arr[i][0] <= endpoint1){
            endpoint0 = endpoint1;
            endpoint1 = arr[i][1];
            count++;
        }
        else{
            endpoint1 = arr[i][1];
            endpoint0 = endpoint1-1;
            count += 2;
        }
        // cout << endpoint0 << " " << endpoint1 << endl;
    }

    return count;
}
