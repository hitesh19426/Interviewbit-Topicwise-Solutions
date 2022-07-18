string Solution::solve(string A) {
    int end = A.size()-1;
    string ans = "";
    while(end >= 0){
        while(end>=0 && A[end] == ' ')
            end--;
        int len = 0;
        while(end>=0 && A[end] != ' ')
            end--, len++;
        ans += A.substr(end+1, len) + " ";
    }
    while(ans.back() == ' ')
        ans.pop_back();
    return ans;
}
