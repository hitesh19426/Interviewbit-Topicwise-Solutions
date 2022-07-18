vector<int> Solution::solve(string s) {
    vector<int> count(26, 0);
    for(char c: s)
        count[c-'a']++;
    return count;
}
