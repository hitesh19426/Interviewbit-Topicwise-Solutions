bool is_palindrome(int n){
    string s = to_string(n);
    int i = 0, j = s.size()-1;
    while(i<j){
        if(s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}

int Solution::solve(int a, int b, int k) {
    vector<int> palindrome;
    for(int i=a; i<=b; i++){
        if(is_palindrome(i)){
            palindrome.push_back(i);
        }
    }

    if(palindrome.empty())
        return 0;

    int start = 0, ans = 0;
    for(int i=0; i<palindrome.size(); i++){
        while(start < i && palindrome[i] - palindrome[start] > k)
            start++;
        ans = max(ans, i-start+1);
    }

    return ans;
}
