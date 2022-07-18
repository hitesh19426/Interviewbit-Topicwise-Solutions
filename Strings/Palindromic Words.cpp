bool is_palindrome(string &s){
    int low = 0, high = s.size()-1;
    while(low < high && s[low] == s[high])
        low++, high--;
    return low >= high;
}
int Solution::solve(string A) {
    stringstream ss(A);
    string word;
    int ans = 0;
    while(ss >> word){
        ans += is_palindrome(word);
    }
    return ans;
}
