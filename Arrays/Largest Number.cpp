bool comparator(const int &A, const int& B){
    const string a = to_string(A);
    const string b = to_string(B);
    return a + b > b + a;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<int> arr(A.begin(), A.end());
    sort(arr.begin(), arr.end(), comparator);

    string ans = "";
    for(auto x: arr)
        ans += to_string(x);
    
    int i;
    while(i<ans.size()-1 && ans[i]=='0')
        i++;
    return ans.substr(i);
}
