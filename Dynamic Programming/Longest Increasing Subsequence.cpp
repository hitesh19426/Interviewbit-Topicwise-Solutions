int Solution::lis(const vector<int> &arr) {
    vector<int> dp;
    for(int x: arr){
        auto itr = lower_bound(dp.begin(), dp.end(), x);
        if(itr == dp.end()){
            dp.push_back(x);
        }
        else{
            *itr = x;
        }
    }

    return dp.size();
}
