int Solution::maxSubArray(const vector<int> &A) {
    int sum = A[0], ans = A[0];
    for(int i=1; i<A.size(); i++){
        sum = max(A[i], sum+A[i] );
        ans = max(ans, sum);
    }

    return ans;
}
