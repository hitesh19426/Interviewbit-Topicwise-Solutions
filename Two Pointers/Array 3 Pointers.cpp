int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int s1 = A.size(), s2 = B.size(), s3 = C.size();
    int min_value = INT_MAX;
    while(i<s1 && j<s2 && k<s3){
        int val = max(abs(A[i]-B[j]), abs(B[j]-C[k]));
        val = max(val, abs(C[k]-A[i]));
        min_value = min(min_value, val);

        if(val == abs(A[i]-B[j])){
            (A[i]>B[j] ? j++ : i++);
        }
        else if(val == abs(B[j]-C[k])){
            (B[j]>C[k] ? k++ : j++);
        }
        else{
            (C[k]>A[i] ? i++ : k++);
        }
    }

    return min_value;
}
