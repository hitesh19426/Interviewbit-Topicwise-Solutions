int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() < 3)
        return A.size();

    int ans = 1;
    for(int i=0; i<A.size(); i++){
        int same = 0, max_count = 1;
        map<pair<int, int>, int> slopes;
        for(int j=i+1; j<A.size(); j++){
            int x1 = A[i], x2 = A[j], y1 = B[i], y2 = B[j];
            if(x2==x1 && y2 == y1){
                same++;
                continue;
            }
            
            int num = (y2-y1), dem = (x2-x1), gcd = __gcd(abs(num), abs(dem));
            num /= gcd, dem /= gcd;
            if(dem == 0)
                num = 1;
            if(dem < 0)
                dem = -dem, num = -num;
            
            if(slopes.find({num, dem}) == slopes.end())
                slopes[{num, dem}] = 2;
            else
                slopes[{num, dem}]++;
            max_count = max(max_count, slopes[{num, dem}]);
        }
        ans = max(ans, max_count + same);
    }
    
    return ans;
}
