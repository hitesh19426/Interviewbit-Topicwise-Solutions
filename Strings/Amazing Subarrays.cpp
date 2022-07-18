int isvowel(char c){
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int Solution::solve(string A) {
    int count = 0, n = A.size();
    for(int i=0; i<n; i++){
        if(isvowel(A[i])){
            count += n-i;
            count %= 10003;
        }
    }

    return count;
}
