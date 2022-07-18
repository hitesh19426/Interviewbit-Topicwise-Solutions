int diff(string &a, string &b){
    int ans = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i])
            ans++;
    }
    return ans;
}

int Solution::solve(string a, string b, vector<string> &dict) {
    int n = dict.size();
    
    dict.push_back(a);
    dict.push_back(b);

    vector<bool> vis(n+2, false);
    vector<int> dist(n+2, INT_MAX);

    queue<int> queue;
    queue.push(n);
    vis[n] = true;
    dist[n] = 0;

    while(not queue.empty()){
        auto curr = queue.front();
        queue.pop();

        if(curr == n+1)
            return dist[curr]+1;

        for(int i=0; i<dict.size(); i++){
            if(!vis[i] && diff(dict[curr], dict[i]) == 1){
                queue.push(i);
                vis[i] = true;
                dist[i] = dist[curr]+1;
            }
        }
    }
    
    return 0;
}
