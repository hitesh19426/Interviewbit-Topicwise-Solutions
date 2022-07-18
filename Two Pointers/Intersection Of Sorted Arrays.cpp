vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> ans;
    int i=0, j=0, m=A.size(), n=B.size();
    while(i<m && j<n){
        if(A[i] < B[j])
            i++;
        else if(A[i] > B[j])
            j++;
        else{
            ans.push_back(A[i]);
            i++, j++;
        }
    }

    return ans;
}
