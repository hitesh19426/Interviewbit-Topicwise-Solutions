int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int i = 0, j = 0;
    while(i<(int)A.size() && j<(int)A.size()){
        int diff = A[j]-A[i];
        if(diff == B && (i!=j)){
            return 1;
        }
        else if(diff > B){
            i++;
        }
        else{
            j++;
        }
    }
    
    return 0;
}
