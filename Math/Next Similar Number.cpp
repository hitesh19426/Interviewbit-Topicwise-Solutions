string Solution::solve(string s) {
    bool ans = next_permutation(s.begin(), s.end());
    if(ans)
        return s;
    return "-1";
}
