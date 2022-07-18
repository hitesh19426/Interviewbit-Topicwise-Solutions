vector<int> Solution::solve(vector<int> &arr) {
    vector<int> ans(arr.size(), 1);

    int product = 1, mod = 1e9+7;
    for(int i=0; i<arr.size(); i++){
        ans[i] *= product;
        ans[i] %= mod;
        product = (int)(((long long)arr[i]*product)%mod);
    }

    product = 1;
    for(int i=arr.size()-1; i>=0; i--){
        ans[i] = (int)(((long long)ans[i]*(long long)product)%mod);
        // product *= arr[i];
        // product %= mod;
        product = (int)(((long long)arr[i]*product)%mod);
    }

    return ans;
}
