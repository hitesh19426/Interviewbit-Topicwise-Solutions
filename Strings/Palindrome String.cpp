int Solution::isPalindrome(string A) {
    int low = 0, high = A.size()-1;
    while(low <= high){
        if(isalnum(A[low]) == false){
            low++;
        }
        else if(isalnum(A[high]) == false){
            high--;
        }
        else if(tolower(A[low]) != tolower(A[high])){
            return false;
        }
        else{
            low++, high--;
        }
    }
    return true;
}
