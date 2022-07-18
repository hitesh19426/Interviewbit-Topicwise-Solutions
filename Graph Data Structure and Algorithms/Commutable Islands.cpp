vector<int> parent, size;

void make_set(int v){
    parent[v] = v;
    ::size[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        if(::size[a] < ::size[b])
            swap(a, b);
        parent[b] = a;
        ::size[a] += ::size[b];
    }
}

int Solution::solve(int n, vector<vector<int>> &edges) {
    parent.assign(n+1, 0);
    ::size.assign(n+1, 0);

    for(int i=1; i<=n; i++){
        make_set(i);
    }

    sort(edges.begin(), edges.end(), [](auto &a, auto &b) -> bool {
        return a[2] < b[2];
    });

    int ans = 0;
    for(int i=0; i<edges.size(); i++){
        if(find_set(edges[i][0]) != find_set(edges[i][1])){
            union_set(edges[i][0], edges[i][1]);
            ans += edges[i][2];
        }
    }

    return ans;
}
