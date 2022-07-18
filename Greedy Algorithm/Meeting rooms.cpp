int Solution::solve(vector<vector<int> > &arr) {
    vector<int> start, end;
    for(int i=0; i<arr.size(); i++){
        start.push_back(arr[i][0]);
        end.push_back(arr[i][1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int count = 0, max_count = 0, s = 0, e = 0;
    while(s<start.size()){
        if(start[s] < end[e]){
            count++;
            max_count = max(max_count, count);
            s++;
        }
        else{
            count--;
            e++;
        }
    }

    return max_count;
}
