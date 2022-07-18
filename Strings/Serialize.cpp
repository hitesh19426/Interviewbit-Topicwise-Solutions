string Solution::serialize(vector<string> &A) {
    string ans = "";
    for(string &s: A){
        ans += s + to_string(s.size()) + '~';
    }
    return ans;
}
