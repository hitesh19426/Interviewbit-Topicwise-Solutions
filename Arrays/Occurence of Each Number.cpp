vector<int> Solution::findOccurences(vector<int> &arr) {
    map<int, int> map;
    for(int x: arr)
        map[x]++;
    
    vector<int> ans;
    for(auto pa: map)
        ans.push_back(pa.second);
    return ans;
}
