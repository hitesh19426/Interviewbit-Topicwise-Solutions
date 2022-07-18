int Solution::solve(string A) {
    int open = 0, count = 0;
    for(char c:A){
        if(c == '(')
            open++;
        else{
            open--;
        }
        if(open<0){
            count += -open;
            open = 0;
        }
    }
    return open+count;
}
