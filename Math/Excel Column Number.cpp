int Solution::titleToNumber(string A) {
    int ans = 0, pow = 1;
    for(int i=A.size()-1; i>=0; i--){
        ans += (A[i]-'A'+1)*pow;
        pow *= 26;
    }
    return ans;
}
