long long product(long long n){
    long long ans = 1, mod = (1e9+7);
    for(long long i=1; i*i<=n; i++){
        if(n%i == 0){
            if(i != n/i){
                ans *= (i*n/i), ans %= mod;
            }
            else{
                ans *= i, ans %= mod;
            }
        }
    }

    return ans;
}

vector<long long> count_number(vector<int>& A){
    int n = A.size();
    stack<int> stack;
    A.push_back(INT_MAX);
    vector<long long> count_in_subarray(n);

    for(int i=0; i<=n; i++){
        while(not stack.empty() && A[stack.top()] < A[i]){
            int top = stack.top();
            stack.pop();

            long long right = i-top;
            long long left = (stack.empty() ? top+1 : top-stack.top());

            count_in_subarray[top] = left*right;
        }
        stack.push(i);
    }
    
    A.pop_back();
    return count_in_subarray;
}


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();

    vector<long long> count_in_subarray = count_number(A);
    vector<pair<long long, long long>> umap;
    for(int i=0; i<n; i++){
        umap.push_back({product(A[i]), count_in_subarray[i]});
    }

    sort(umap.begin(), umap.end(), [](const auto &a, const auto &b) -> bool {
        return a.first > b.first;
    });

    vector<long long> freq_sum(n);
    for(int i=0; i<n; i++){
        freq_sum[i] = (i==0 ? umap[i].second : umap[i].second + freq_sum[i-1] );
    }

    vector<int> ans;
    for(int query: B){
        int index = lower_bound(freq_sum.begin(), freq_sum.end(), query) - freq_sum.begin();
        ans.push_back(umap[index].first);
    }

    return ans;
}
