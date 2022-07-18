pair<int, int> expand_around_center(string &s, int low, int high){
    int count = 0, i = low, j = high, n = s.size();
    while(i>=0 && j<n && s[i] == s[j])
        i--, j++;
    return {i+1,j-i-1};
}

string Solution::longestPalindrome(string A) {
    int maxlen = 0, start = -1;
    for(int i=0; i<A.size(); i++){
        auto t1 = expand_around_center(A, i, i);
        auto t2 = expand_around_center(A, i, i+1);
        if(t1.second > maxlen){
            start = t1.first, maxlen = t1.second;
        }
        if(t2.second> maxlen){
             start = t2.first, maxlen = t2.second;
        }
    }

    return A.substr(start, maxlen);
}
