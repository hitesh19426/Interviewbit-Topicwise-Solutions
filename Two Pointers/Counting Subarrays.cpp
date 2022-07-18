int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), start = 0, sum = 0, count=0;
    for(int end=0; end<n; end++){
        sum += A[end];
        while(sum >= B && start<=end){
            sum -= A[start++];
        }
        count += end-start+1;
    }
    return count;
}
