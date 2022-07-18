int Solution::highestScore(vector<vector<string> > &arr) {
    unordered_map<string, pair<int, int>> scores;
    for(auto player: arr){
        scores[player[0]].first += stoi(player[1]);
        scores[player[0]].second++;
    }
    
    int ans = 0;
    for(auto [player, value]: scores){
        auto [sum, count] = value;
        ans = max(ans, sum/count);
    }
    return ans;
}
