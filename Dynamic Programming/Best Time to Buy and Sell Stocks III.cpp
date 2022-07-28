int Solution::maxProfit(const vector<int> &prices) {
    int n = prices.size();
    int held1[n+1], start, sold1[n+1], held2[n+1], sold2[n+1];
    held1[0] = held2[0] = INT_MIN, sold1[0] = sold2[0] = start = 0;
    
    for(int i=1; i<=n; i++){
        held1[i] = max(held1[i-1], start - prices[i-1]);
        sold1[i] = max(sold1[i-1], held1[i-1] + prices[i-1]);
        
        held2[i] = max(held2[i-1], sold1[i-1] - prices[i-1]);
        sold2[i] = max(sold2[i-1], held2[i-1] + prices[i-1]);
    }
    
    return max(sold1[n], sold2[n]);
}
