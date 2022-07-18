void extendSubset(vector<int>& arr, int start, vector<int>& current_subset, vector<vector<int>>& all_subsets){
    all_subsets.push_back(current_subset);  // insert current set
    for(int i = start; i<arr.size(); i++){  // 
        current_subset.push_back(arr[i]);   // extend current set
        extendSubset(arr, i+1, current_subset, all_subsets);    // extend the set from i+1 to n
        current_subset.pop_back();  // pop current element, then start extend from i+1 element
    }
}

vector<vector<int>> Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> all_subsets;
    vector<int> current_subset;
    extendSubset(A, 0, current_subset, all_subsets);
    return all_subsets;
}

/*

start from base subset, extend till you can, then abort
then pop element from that base and again extend.


[] -> [1] -> [1,2] -> [1,2,3] -> [1,2,3,4] -> abort
                                    |
                                   [1] -> [1,3] -> [1,3,4]
                                                      |
                                                    [1,3] -> abort
                                                      |
                                                     [1] -> [1,4] -> abort
                                                              |
                                                             [1]
                                                              |
                                                              []

    then you will come here.

      [2] -> [2,3] -> [2,3,4] -> abort
       |
      pop
       |
      [3] -> [3,4] -> abort
       |
      pop
       |
      [4] -> abort

    correct ^^ this too.


start from []

insert 1 -> extend from 1+1 with base as 1
pop 1
insert 2 -> extend from 2+1 with base as 2
pop 2
insert 3 -> extend from 3+1 with base as 3
*/
