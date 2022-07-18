bool is_palindrome(string &s, int low, int high){
    while(low<= high && s[low] == s[high])
        low++, high--;
    return low > high;    
}

vector<vector<string>> helper(string &s, int ind){
    if(ind < 0)
        return {{}};
    
    vector<vector<string>> ans;
    for(int i=0; i<=ind; i++){
        if(is_palindrome(s, i, ind)){
            auto prev = helper(s, i-1);
            auto palindrome = s.substr(i, ind-i+1);
            for(auto vec: prev){
                vec.push_back(palindrome);
                ans.push_back(vec);
            }
        }
    }
    return ans;
}

vector<vector<string> > Solution::partition(string s) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    auto ans = helper(s, s.size()-1);
    sort(ans.begin(), ans.end());
    return ans;
}
