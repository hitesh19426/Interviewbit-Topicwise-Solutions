int diff(string& a, string &b){
    int ans = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i])
            ans++;
    }
    return ans;
}

void dfs(string& start, string &target, unordered_map<string, bool>& vis, vector<string>& dict, vector<string>& path, vector<vector<string>>& ans){
    vis[start] = true;
    path.push_back(start);

    if(start == target){
        ans.push_back(path);
    }

    for(int i=0; i<dict.size(); i++){
        if(!vis[dict[i]] && diff(dict[i], start) == 1){
            dfs(dict[i], target, vis, dict, path, ans);
        }
    }

    vis[start] = false;
    path.pop_back();
}

int find_min_dist(string &start, string& end, unordered_set<string>& dict){
    queue<string> queue;
    unordered_map<string, int> dist;
    queue.push(start);
    dist[start] = 0;
    
    while(!queue.empty()){
        auto word = queue.front();
        queue.pop();
        
        int curr_dist = dist[word];
        if(word == end)
            return curr_dist;
        
        for(char &letter: word){
            char orig = letter;
            for(char c='a'; c<='z'; c++){
                letter = c;
                if(dict.find(word) != dict.end() && dist.find(word) == dist.end()){
                    queue.push(word);
                    dist[word] = curr_dist+1;
                }
            }
            letter = orig;
        }
    }
    
    return -1;
}

void dfs(string start, string &target, int dist, vector<string>& path, vector<vector<string>>& paths, unordered_set<string>& vis, unordered_set<string>& dict, int min_dist){
    if(dist > min_dist)
        return;
    path.push_back(start);
    vis.insert(start);
    if(start == target){
        paths.push_back(path);
        path.pop_back();
        vis.erase(start);
        return;
    }
    
    for(char &letter: start){
        char orig = letter;
        for(char c='a'; c<='z'; c++){
            letter = c;
            if(dict.find(start) != dict.end() && vis.find(start) == vis.end()){
                dfs(start, target, dist+1, path, paths, vis, dict, min_dist);
            }
        }
        letter = orig;
    }
    
    vis.erase(start);
    path.pop_back();
}

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &words) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_set<string> dict(words.begin(), words.end());
    if(dict.find(end) == dict.end())
        return {};
    
    int min_dist = find_min_dist(start, end, dict);
    if(min_dist == -1)
        return {};
    
    vector<string> path;
    vector<vector<string>> paths;
    unordered_set<string> vis;
    int dist = 0;
    dfs(start, end, 0, path, paths, vis, dict, min_dist);
    return paths;
}
