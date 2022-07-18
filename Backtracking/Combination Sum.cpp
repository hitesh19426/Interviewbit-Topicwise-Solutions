vector<vector<int>> generateCombination(vector<int>& arr, int i, int target){
    if(target == 0)
        return {{}};
    if(target < 0 || i < 0)
        return {};

    auto withouti = generateCombination(arr, i-1, target);
    auto withi = generateCombination(arr, i, target - arr[i]);

    for(auto &comb: withi){
        comb.push_back(arr[i]);
        withouti.push_back(comb);
    }
    return withouti;
}

vector<vector<int>> Solution::combinationSum(vector<int> &arr, int target) {
    
}
