vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<vector<int>, vector<int>> map;
    int i = 1;
    for(const string &s: A){
        vector<int> count(26, 0);
        for(char c:s)
            count[c-'a']++;
        map[count].push_back(i);
        i++;
    }

    vector<vector<int>> ans;
    for(auto pa: map){
        ans.push_back(pa.second);
    }
    return ans;
}
