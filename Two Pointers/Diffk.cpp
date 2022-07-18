int Solution::diffPossible(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int i = 0, j = 0, n = A.size();
    while(i<n && j<n){
        if(A[j] - A[i] == B && i!=j)
            return 1;
        else if(A[j] - A[i] < B){
            j++;
        }
        else{
            i++;
        }
    }
    return 0;
}
