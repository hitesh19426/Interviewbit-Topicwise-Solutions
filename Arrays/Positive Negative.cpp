vector<int> Solution::solve(vector<int> &arr) {
    int pos = 0, neg = 0;
    for(int x: arr){
        if(x>0)
            pos++;
        if(x<0)
            neg++;
    }
    return {pos, neg};
}
