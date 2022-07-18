int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int val1 =0;
    for(int x: A){
        if(x>C)
            val1++;
    }

    int val2 = 0;
    for(int x: B){
        if(x<C){
            val2++;
        }
    }

    return max(val1, val2);
}
