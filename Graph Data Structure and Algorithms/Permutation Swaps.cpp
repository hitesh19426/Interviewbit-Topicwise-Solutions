#define N 100005
int parent[N], size[N];

void make_set(int a){
    ::parent[a] = a;
    ::size[a] = 1;
}

int find_set(int v){
    if(v == ::parent[v])
        return v;
    return ::parent[v] = find_set(::parent[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        if(::size[a] < ::size[b])
            swap(a, b);
        ::size[a] += ::size[b];
        ::parent[b] = a;
    }
}

int Solution::solve(vector<int> &a, vector<int> &b, vector<vector<int>> &edges) {
    int n = a.size();
    for(int i=0; i<n; i++){
        make_set(i);
    }

    for(auto e: edges){
        union_set(e[0]-1, e[1]-1);
    }

    vector<int> index(n+1, 0);
    for(int i=0; i<n; i++){
        index[a[i]] = i;
    }
    for(int i=0; i<n; i++){
        if(a[i] != b[i] && find_set(index[a[i]]) != find_set(index[b[i]]))
            return false;
    }
    return true;
}
