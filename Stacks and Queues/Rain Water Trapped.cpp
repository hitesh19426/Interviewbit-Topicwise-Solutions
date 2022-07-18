int Solution::trap(const vector<int> &A) {
    int water = 0, leftmax = 0, rightmax = 0;
    int left = 0, right = A.size()-1;
    
    while(left <= right){
        if(leftmax < rightmax){
            if(A[left] > leftmax){
                leftmax = A[left];
            }
            else{
                water += max(leftmax - A[left], 0);
                left++;
            }
        }
        else{
            if(A[right] > rightmax){
                rightmax = A[right];
            }
            else{
                water += max(rightmax - A[right], 0);
                right--;
            }
        }
    }

    return water;
}
