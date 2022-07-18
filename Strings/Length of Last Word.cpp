int Solution::lengthOfLastWord(const string A) {
    int end = A.size()-1;
    while(end >=0 && A[end] == ' ')
        end--;

    int count = 0;
    while(end>=0 && A[end] != ' ')
        end--, count++;
    return count;
}
