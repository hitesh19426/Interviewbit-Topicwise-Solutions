int Solution::jump(vector<int> &arr) {
    if(arr.size() == 1)
        return 0;
    
    int start = 0, end = 0, dist = 0;
    while(start < arr.size()){
        auto nextStart = end+1, nextEnd = -1;
        for(int i=start; i<=min(end, (int)arr.size()-1); i++){
            nextEnd = max(nextEnd, i+arr[i]);
            if(i == arr.size()-1)
                return dist;
        }
        if(nextEnd == -1){
            return -1;
        }
        start = nextStart, end = nextEnd, dist++;
    }
    
    return -1;
}
