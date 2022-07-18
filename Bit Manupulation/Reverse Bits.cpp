unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    for(unsigned int low = 0, high = 31; low < high; low++, high--){
        bool bit1 = A&(1<<low), bit2 = A&(1<<high);
        if( bit1 != bit2 ){
            A ^= (1<<low)^(1<<high);
        }
    }
    return A;
}
