int Solution::solve(vector<vector<int> > &intervals) {
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) -> bool {
        return a[1] < b[1];
    });

    int end = intervals[0][1], count = 1;
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0] > end){
            count++;
            end = intervals[i][1];
        }
    }

    return count;
}
