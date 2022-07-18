#define mod 1000000007
long long dfs(vector<vector<int>>& graph, vector<int>& values, int src, int parent, long long total, long long &ans){
    long long sum = values[src-1];
    for(int v: graph[src]){
        if(v != parent)
            sum += dfs(graph, values, v, src, total, ans);
    }

    ans = max(ans, (sum*(total-sum)));
    return sum;
}

int Solution::deleteEdge(vector<int> &values, vector<vector<int>> &edges) {
    int n = values.size();
    vector<vector<int>> graph(n+1, vector<int>());

    for(auto edge: edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    long long total = 0;
    for(int val: values)
        total += val;

    int root = 1, parent = -1;
    long long ans = 0;
    dfs(graph, values, root, parent, total, ans);

    cout << ans << endl;
    return (int)(ans%mod);
}
