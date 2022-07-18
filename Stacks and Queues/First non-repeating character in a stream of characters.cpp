string Solution::solve(string A) {
    string ans = "";
    queue<char> queue;
    unordered_map<char, int> count;

    for(char ch:A){
        if(count[ch] == 0){
            queue.push(ch);
        }
        count[ch]++;

        while(not queue.empty() && count[queue.front()] > 1 ){
            queue.pop();
        }
        ans += (queue.empty() ? '#' : queue.front());
    }

    return ans;
}
