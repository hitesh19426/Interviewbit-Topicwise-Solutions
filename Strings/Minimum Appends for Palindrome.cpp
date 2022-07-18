int Solution::solve(string A) {
    string rev = A;
    reverse(A.begin(), A.end());

    A += ':'+ rev;
    int n = A.size(), i = 1, j = 0, len = rev.size();
    vector<int> lps(n);
    lps[0] = 0;
    while(i<n){
        if(A[i] == A[j]){
            lps[i] = j+1;
            i++, j++;
        }
        else if(j!=0){
            j = lps[j-1];
        }
        else{
            lps[i] = 0, i++;
        }
    }

    return len-lps.back();
}
