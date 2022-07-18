vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> map;
    for(int i=0; i<A.size(); i++){
        if(map.find(B-A[i]) != map.end())
            return {map[B-A[i]], i+1};
        if(map.find(A[i]) == map.end())
            map[A[i]] = i+1;
    }
    return {};
}
