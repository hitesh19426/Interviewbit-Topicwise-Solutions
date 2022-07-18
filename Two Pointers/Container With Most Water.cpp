int Solution::maxArea(vector<int> &A) {
    if(A.empty())
        return 0;

    int left = 0, right = A.size()-1, max_water = 0;
    while(left <= right){
        max_water = max(max_water, (right-left)*min(A[left], A[right]) );

        if(A[left] < A[right])
            left++;
        else right--;
    }

    return max_water;
}
