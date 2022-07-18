vector<string> Solution::specialStrings(vector<string> &arr) {
    vector<string> prev{""};
    for(auto &s: arr){
        vector<string> curr;
        for(auto &comb: prev){
            for(auto letter: s){
                curr.push_back(comb + letter);
            }
        }
        prev = curr;
    }
    return prev;
}
