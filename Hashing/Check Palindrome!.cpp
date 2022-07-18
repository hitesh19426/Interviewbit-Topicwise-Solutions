int Solution::solve(string A) {
    int count[26] = {0};
    for(int i=0; i<A.size(); i++){
        count[A[i]-'a']++;
    }
    int odd = 0;
    for(int i=0; i<26; i++){
        if(count[i]&1)
            odd++;
    }
    return odd<=1;
}
