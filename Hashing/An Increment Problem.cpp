vector<int> Solution::solve(vector<int> &arr) {
    map<int, priority_queue<int, vector<int>, greater<int>> > position;
    for(int i=0; i<arr.size(); i++){
        if(position.find(arr[i]) != position.end()){
            auto ind = position[arr[i]].top();
            position[arr[i]].pop();
            arr[ind]++;
            position[arr[i]+1].push(ind);
        }
        position[arr[i]].push(i);
    }
    
    return arr;
}
