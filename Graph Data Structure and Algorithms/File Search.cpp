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
        ::size[a] += ::size[b];
        parent[b] = a;
    }
}

int Solution::breakRecords(int n, vector<vector<int>> &edges) {
    parent.resize(n+1);
    ::size.resize(n+1);

    for(int i=1; i<=n; i++)
        make_set(i);

    int count = n;
    for(auto e: edges){
        if(find_set(e[0]) != find_set(e[1])){
            union_set(e[0], e[1]);
            count--;
        }
    }

    return count;
}
