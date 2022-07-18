vector<string> Solution::letterCombinations(string A) {
    vector<string> map{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> prev{""};
    for(char c: A){
        vector<string> curr;
        for(auto &comb: prev){
            for(auto letter: map[c-'0'])
                curr.push_back(comb + letter);
        }
        prev = curr;
    }
    return prev;
}
