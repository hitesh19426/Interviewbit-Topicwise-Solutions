int Solution::repeatedNumber(const vector<int> &arr) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int can1 = -1, can2 = -1, count1 = 0, count2 = 0;
    for(const int x: arr){
        if(x == can1){
            count1++;
        }
        else if(x == can2){
            count2++;
        }
        else if(count1 == 0){
            can1 = x;
            count1++;
        }
        else if(count2 == 0){
            can2 = x;
            count2++;
        }
        else{
            count1--, count2--;
        }
    }

    count1 = 0, count2 = 0;
    for(const int x: arr){
        if(x == can1)
            count1++;
        else if(x == can2)
            count2++;
    }

    int n = arr.size();
    if(count1 > n/3)
        return can1;
    if(count2 > n/3)
        return can2;
    return -1;
}
