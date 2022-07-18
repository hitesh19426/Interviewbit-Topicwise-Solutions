void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size(), n = B.size();
    A.resize(m+n);

    int i = m-1, j = n-1, k=m+n-1;
    while(i>=0 && j>=0){
        if(A[i] > B[j]){
            A[k--] = A[i--];
        }
        else{
            A[k--] = B[j--];
        }
    }
    while(i>=0)
        A[k--] = A[i--];
    while(j>=0)
        A[k--] = B[j--];
}
