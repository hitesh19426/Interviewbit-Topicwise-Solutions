vector<int> Solution::solve(vector<int> &A) {
    int low = 0, high = A.size()-1, k = high;
    vector<int> ans(high+1);
    while(low <= high){
        if(abs(A[low]) > abs(A[high])){
            ans[k--] = A[low]*A[low++];
        }
        else{
            ans[k--] = A[high]*A[high--];
        }
    }

    return ans;
}
