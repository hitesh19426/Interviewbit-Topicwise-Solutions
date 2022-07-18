bool isvowel(char c){
    return (c == 'a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int Solution::solve(string A) {
    int n = A.size();
    int vowel = 0, constant = 0;

    (isvowel(A[0]) ? vowel++ : constant++ );
    int ans = 0, mod = (1e9+7);
    for(int i=1; i<n; i++){
        if(isvowel(A[i])){
            ans += constant;
            vowel++;
        }
        else{
            ans += vowel;
            constant++;
        }
        ans %= mod;
    }

    return ans;
}
