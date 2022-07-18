long Solution::countSalutes(string A) {
    long long count = 0, arrow = 0, n = A.size();
    for(int i=0; i<n; i++){
        if(A[i] == '<'){
            count += arrow;
        }
        else{
            arrow++;
        }
    }
    return count;
}
