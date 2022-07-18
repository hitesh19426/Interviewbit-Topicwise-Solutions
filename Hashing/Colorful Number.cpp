int Solution::colorful(int A) {
    string s = to_string(A);
    int n = s.size();
    unordered_set<int> set;
    for(int i=0; i<n; i++){
        int product = 1;
        for(int j=i; j<n; j++){
            product *= (s[j] - '0');
            if(set.find(product) != set.end())
                return false;
            set.insert(product);
        }
    }
    return true;
}
