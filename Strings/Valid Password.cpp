int Solution::solve(string A) {
    bool digit = false, lower = false, upper = false, special = false;
    for(char c: A){
        if(isdigit(c))
            digit = true;
        else if(islower(c))
            lower = true;
        else if(isupper(c))
            upper = true;
        else
            special = true;
    }

    if(A.size() < 8 || A.size()>15 || !digit || !lower || !upper || !special)
        return false;
    return true;
}
