vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = 1<<A;
    vector<int> ans;
    for(int i=0; i<n; i++){
        ans.push_back(i^(i/2));
    }
    return ans;
}
