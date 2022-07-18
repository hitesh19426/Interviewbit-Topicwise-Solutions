bool ispalindrome(string &s, int low, int high){
    while(low<=high && s[low] == s[high])
        low++, high--;
    return low>high;
}
int Solution::solve(string A) {
    int low = 0, high = A.size()-1;
    while(low<=high){
        if(A[low] == A[high]){
            low++, high--;
        }
        else{
            if(ispalindrome(A, low+1, high) || ispalindrome(A, low, high-1))
                return true;
            return false;
        }
    }
    return true;
}
