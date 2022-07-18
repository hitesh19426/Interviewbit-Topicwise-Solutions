int Solution::hammingDistance(const vector<int> &arr) {
    long long ans = 0, mod = (1e9+7), n = arr.size();
    for(int i=0; i<32; i++){
        long long onebit = 0;
        for(const int x: arr){
            if(x&(1<<i))
                onebit++;
        }

        ans += onebit*(n-onebit);
        ans %= mod;
    }
    return (ans*2)%mod;
}
