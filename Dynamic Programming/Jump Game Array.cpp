int Solution::canJump(vector<int> &arr) {
    if(arr.size() == 1)
        return true;
    
    int start = 0, end = 0, dist = 0;
    while(start < arr.size()){
        auto nextStart = end+1, nextEnd = -1;
        for(int i=start; i<=end; i++){
            nextEnd = max(nextEnd, i+arr[i]);
            if(i == arr.size()-1)
                return true;
        }
        if(nextEnd == -1)
            return false;
        start = nextStart, end = nextEnd;
    }
    
    return false;
}
