int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() <= 2)
        return A.size();
    int to_insert = 2;
    for(int i=2; i<(int)A.size(); i++){
        if(A[i] != A[to_insert-1] || A[i] != A[to_insert-2]){
            A[to_insert++] = A[i];
        }
    }
    return to_insert;
}
