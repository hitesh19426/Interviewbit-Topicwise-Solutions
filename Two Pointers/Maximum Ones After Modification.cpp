int Solution::solve(vector<int> &A, int B) {
    int start = 0, end = 0, count = 0, n = A.size(), length = 0;
    while(end < n){
        if(A[end] == 0){
            count++;
        }
        while(count>B && start<=end){
            if(A[start] == 0)
                count--;
            start++;
        }
        length = max(length, end-start+1);
        end++;
    }

    return length;
}
