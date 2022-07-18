int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> maxheap;
    for(int x:B)
        maxheap.push(x);

    long long ans = 0, mod = (1e9+7);
    while(A--){
        long long val = maxheap.top();
        ans += val;
        ans %= mod;
        maxheap.pop();
        maxheap.push(val/2);
    }

    return (int)ans;
}
