int Solution::solve(int n) {
    int count = 0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int k = sqrt(i*i + j*j);
            if(k<=n && k*k == i*i+j*j)
                count++;
            
        }
    }

    return count;
}
