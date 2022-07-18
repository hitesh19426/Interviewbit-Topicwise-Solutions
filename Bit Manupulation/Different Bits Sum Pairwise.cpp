int Solution::cntBits(vector<int> &A) {
    long long count_one[32] = {0};

    for(int a:A){
        for(int i=0; i<32; i++){
            if(a&(1<<i)){
                count_one[i]++;
            }
        }
    }

    long long ans = 0, n = A.size(), mod = (1e9+7);
    for(int i=0; i<32; i++){
        ans += count_one[i] * (n-count_one[i]);
        ans %= mod;
    }
    ans *= 2;
    ans %= mod;

    return (int)ans;
}
