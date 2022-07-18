int Solution::bulbs(vector<int> &arr) {
    int required = 0, count = 0;
    for(int x: arr){
        if(x == required){
            count++;
            required = 1-required;
        }
    }

    return count;
}
