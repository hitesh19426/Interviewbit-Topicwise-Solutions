const int maxn = 205;
int dp[maxn][maxn];
int prefix[maxn];

int find_sum(int i, int j){
    if(j<i)
        return 0;
    return prefix[j+1] - prefix[i];
}

int helper(vector<int>& arr, int i, int j){
    if(j<=i)
        return 0;
    if(dp[i][j] != INT_MAX)
        return dp[i][j];

    int cost = INT_MAX;
    for(int k=i; k<j; k++){
        int left_cost = helper(arr, i, k);
        int right_cost = helper(arr, k+1, j);

        int left_sum = find_sum(i, k);
        int right_sum = find_sum(k+1, j);

        int cost_till_now = left_cost + right_cost;
        cost = min(cost, cost_till_now + left_sum + right_sum);
    }

    return dp[i][j] = cost;
}

int Solution::solve(vector<int> &arr) {
    for(int i=0; i<maxn; i++){
        for(int j=0; j<maxn; j++){
            dp[i][j] = INT_MAX;
        }
    }

    prefix[0] = 0;
    for(int i=1; i<=arr.size(); i++)
        prefix[i] = prefix[i-1] + arr[i-1];
    
    return helper(arr, 0, arr.size()-1);
}
