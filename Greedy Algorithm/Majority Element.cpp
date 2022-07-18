int Solution::majorityElement(const vector<int> &arr) {
    int candidate = arr[0], count = 0;
    for(int x : arr){
        if(x == candidate)
            count++;
        else
            count--;
        if(count == 0)
            count = 1, candidate = x;
    }

    return candidate;
}
