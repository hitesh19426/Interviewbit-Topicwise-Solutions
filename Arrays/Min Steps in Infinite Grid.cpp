int Solution::coverPoints(vector<int> &x, vector<int> &y) {
    int ans = 0;
    for(int i=0; i<x.size()-1; i++){
        ans += max(abs(x[i]-x[i+1]), abs(y[i]-y[i+1]));
    }
    return ans;
}
