string Solution::solve(string A) {
    vector<int> freq(26, 0);
    queue<char> queue;
    vector<bool> present(26, false);
    for(char c:A){
        freq[c-'a']++;
        if(!present[c-'a']){
            queue.push(c);
            present[c-'a'] = true;
        }
    }
    string ans = "";
    while(not queue.empty()){
        ans += queue.front() + to_string(freq[queue.front()-'a']);
        queue.pop();
    }
    return ans;
}
