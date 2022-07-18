vector<int> lps_calculate(const string &s){
    int n = s.size(), i = 1, j = 0;
    vector<int> lps(n);
    lps[0] = 0;
    while(i<n){
        if(s[i] == s[j]){
            lps[i] = j+1;
            i++, j++;
        }
        else if(j!=0){
            j = lps[j-1];
        }
        else{
            lps[i] = 0, i++;
        }
    }
    return lps;
}

int search(const string& text, const string& pattern){
    int i = 0, n = text.size();
    int j = 0, m = pattern.size();
    auto lps = lps_calculate(pattern);
    vector<int> index;
    while(i<n){
        if(pattern[j] == text[i]){
            i++, j++;
            if(j == m){
                return i-j;
            }
        }
        else if(j!=0){
            j = lps[j-1];
        }
        else{
            i++;
        }
    }
    return -1;
}

int Solution::strStr(const string text, const string pattern) {
    if(text.empty() || pattern.empty() || text.size()<pattern.size())
        return -1;

    return search(text, pattern);
}
