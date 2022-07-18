string Solution::solve(string A, int B) {
    int count = 0, lastchar = '1', n = A.size();
    string ans = "";

    for(int i=0; i<n; i++){
        if(A[i] != lastchar){
            if(count == B){
                while(count--)
                    ans.pop_back();
            }
            lastchar = A[i];
            count = 1;
        }
        else{
            count++;
        }
        ans += A[i];
    }
    if(count == B){
        while(count--)
            ans.pop_back();
    }
    return ans;
}
