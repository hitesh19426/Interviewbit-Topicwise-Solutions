int Solution::longestSubsequenceLength(const vector<int> &arr) {
    int n = arr.size();
    vector<int> suffix_seq;
    vector<int> suffix_len(n);
    for(int i=n-1; i>=0; i--){
        auto itr = lower_bound(suffix_seq.begin(), suffix_seq.end(), arr[i]);
        int ind = itr - suffix_seq.begin();
        if(itr == suffix_seq.end()){
            suffix_seq.push_back(arr[i]);
        }
        else{
            suffix_seq[ind] = arr[i];
        }
        suffix_len[i] = (ind+1);
    }

    int ans = 0;
    vector<int> prefix;
    for(int i=0; i<arr.size(); i++){
        auto itr = lower_bound(prefix.begin(), prefix.end(), arr[i]);
        int ind = itr-prefix.begin();
        if(itr == prefix.end()){
            prefix.push_back(arr[i]);
        }
        else{
            prefix[ind] = arr[i];
        }
        int lenp = ind;
        int lens = suffix_len[i];
        ans = max(ans, lenp + lens);
    }

    return ans;
}