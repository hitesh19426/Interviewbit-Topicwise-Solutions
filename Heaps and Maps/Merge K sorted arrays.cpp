typedef pair<int, pair<int, int>> node; // value, array index, value index in array.

struct comparator{
    bool operator()(const node &a, const node &b){
        return a.first > b.first;
    }
};

vector<int> Solution::solve(vector<vector<int> > &A) {
    priority_queue<node, vector<node>, comparator> minheap;

    int i = 0;
    for(auto v:A){
        minheap.push({v[0],{i++, 0}});
    }

    vector<int> ans;
    while(not minheap.empty()){
        auto top = minheap.top();
        minheap.pop();

        auto value = top.first;
        auto array_index = top.second.first;
        auto index = top.second.second;

        ans.push_back(A[array_index][index]);
        if(index+1 < A[array_index].size()){
            minheap.push({A[array_index][index+1], {array_index, index+1}});
        }
    }

    return ans;
}
