struct triplet{
    int i, j, sum;
    triplet(int i, int j, int sum) : i(i), j(j), sum(sum) {}
};

struct comparator{
    bool operator()(triplet &n1, triplet &n2){
        return n1.sum < n2.sum;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<triplet, vector<triplet>, comparator> maxheap;
    set<pair<int, int>> vis;
   
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    maxheap.push(triplet(A.size()-1, B.size()-1, A.back()+B.back()));
    vis.insert({A.size()-1, B.size()-1});

    vector<int> ans;
    while(C--){
        auto top = maxheap.top();
        maxheap.pop();

        ans.push_back(top.sum);
        if(vis.find({top.i-1,top.j}) == vis.end() ){
            maxheap.push(triplet(top.i-1, top.j, A[top.i-1]+B[top.j]));
            vis.insert({top.i-1,top.j});
        }
        if(vis.find({top.i,top.j-1}) == vis.end() ){
            maxheap.push(triplet(top.i, top.j-1, A[top.i]+B[top.j-1]));
            vis.insert({top.i,top.j-1});
        }
    }

    return ans;
}
