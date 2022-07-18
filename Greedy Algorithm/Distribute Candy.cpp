int Solution::candy(vector<int> &A) {
    int ans = 0, n = A.size();
    vector<int> left(n, 1), right(n, 1);
   
    for(int i=1; i<n; i++){
        if(A[i] > A[i-1])
            left[i] = left[i-1]+1;
    }

    for(int i=n-2; i>=0; i--){
        if(A[i] > A[i+1])
            right[i] = right[i+1]+1;
    }

    for(int i=0; i<n; i++){
        ans += max(left[i], right[i]);
    }

    return ans;
}

/*
1 5 7 4 3 8 2 1

1 2 3 1 1 2 1 1
*/
