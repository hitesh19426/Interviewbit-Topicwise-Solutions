int Solution::maxArr(vector<int> &arr) {
    // f(i) = a(i)+i, g(i) = a(i)-i;
    int ans = 0, n = arr.size();

    vector<int> f, g;
    for(int i=0; i<n; i++){
        f.push_back(arr[i]+i);
        g.push_back(arr[i]-i);
    }

    int t1 = *max_element(f.begin(), f.end()) - *min_element(f.begin(), f.end());
    int t2 = *max_element(g.begin(), g.end()) - *min_element(g.begin(), g.end());

    return max(t1, t2);
}
