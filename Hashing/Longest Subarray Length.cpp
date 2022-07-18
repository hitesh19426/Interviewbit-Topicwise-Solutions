int Solution::solve(vector<int> &A) {
    unordered_map<int, int> map;
    int sum = 0, length = 0;
    for(int i=0; i<A.size(); i++){
        sum += (A[i] == 0 ? -1 : 1);
        if(sum == 1)
            length = max(length, i+1);
        else if(map.find(sum-1) != map.end()){
            length = max(length, i-map[sum-1]);
        }

        if(map.find(sum) == map.end()){
            map[sum] = i;
        }
    }

    return length;
}
