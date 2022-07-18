int Solution::minimumTotal(vector<vector<int>> &arr){
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = arr.size(), n = arr.back().size();
    vector<int> dp(n, INT_MAX);

    dp[0] = arr[0][0];
    for(int i=1; i<m; i++){
        vector<int> temp(n, INT_MAX);
        for(int j=0; j<=i; j++){
            if(i!=j){
                temp[j] = min(temp[j], arr[i][j] + dp[j]);
            }
            if(j!=0){
                temp[j] = min(temp[j], arr[i][j] + dp[j-1]);
            }
        }
        dp = temp;
    }

    return *min_element(dp.begin(), dp.end());
}
