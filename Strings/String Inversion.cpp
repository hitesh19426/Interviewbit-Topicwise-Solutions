string Solution::solve(string A) {
    for(char &c: A){
        if(islower(c))
            c = toupper(c);
        else
            c = tolower(c);
    }
    return A;
}
