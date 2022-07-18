string Solution::solve(string A, string B) {
    int len = A.size(), bulls = 0, cows = 0;
    vector<int> fa(10, 0), fb(10, 0);
    for(int i=0; i<len; i++){
        if(A[i] == B[i]){
            bulls++;
        }
        else{
            fa[A[i]-'0']++;
            fb[B[i]-'0']++;
        }
    }

    for(int i=0; i<10; i++){
        cows += min(fa[i], fb[i]);
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}
