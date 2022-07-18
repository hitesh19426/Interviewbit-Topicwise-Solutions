int Solution::solve(vector<int> &arr) {
    vector<int> count(arr.size()+1, 0);
    for(int x: arr){
        count[x]++;
    }

    int ans = 0;
    for(int x: count){
        ans += x/2;
    }
    return ans;
}
