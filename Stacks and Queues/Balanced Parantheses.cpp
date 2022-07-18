int Solution::solve(string A) {
    int open = 0;
    for(char ch:A){
        if(ch == '(')
            open++;
        else
            open--;
        if(open < 0)
            return 0;
    }

    if(open == 0)
        return 1;
    return 0;
}
