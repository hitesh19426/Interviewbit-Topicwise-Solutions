struct triplet{
    int i, j, sum;
    triplet(int i, int j, int sum) : i(i), j(j), sum(sum) {}
};

struct comparator{
    bool operator()(const triplet &a, const triplet &b){
        return a.sum < b.sum;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue<triplet, vector<triplet>, comparator> maxheap;
    set<pair<int, int>> vis;

    maxheap.push(triplet(A.size()-1, B.size()-1, A.back() + B.back()) );
    vis.insert({A.size()-1, B.size()-1});

    int n = A.size();
    vector<int> ans;
    while(n--){
        auto top = maxheap.top();
        maxheap.pop();

        ans.push_back(top.sum);
        if(vis.find({top.i-1, top.j}) == vis.end()){
            maxheap.push(triplet(top.i-1, top.j, A[top.i-1] + B[top.j]));
            vis.insert({top.i-1, top.j});
        }
        if(vis.find({top.i, top.j-1}) == vis.end()){
            maxheap.push(triplet(top.i, top.j-1, A[top.i] + B[top.j-1]));
            vis.insert({top.i, top.j-1});
        }
    }
    return ans;
}
