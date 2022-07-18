int Solution::maximumGap(const vector<int> &A) {
    priority_queue<int> pq(A.begin(), A.end());
    int prev = pq.top(), ans = 0;
    while(!pq.empty()){
        ans = max(ans, abs(pq.top()-prev));
        prev = pq.top();
        pq.pop();
    }
    return ans;
}
