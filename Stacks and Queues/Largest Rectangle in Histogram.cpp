int Solution::largestRectangleArea(vector<int> &arr) {
    int n = arr.size();
    vector<int> smallerFromLeft(n), smallerFromRight(n);

    for(int i=0; i<n; i++){
        int left = i-1;
        while(left>=0 && arr[left] >= arr[i])
            left = smallerFromLeft[left];
        smallerFromLeft[i] = left;
    }

    for(int i=n-1; i>=0; i--){
        int right = i+1;
        while(right<n && arr[right] >= arr[i])
            right = smallerFromRight[right];
        smallerFromRight[i] = right;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int width = smallerFromRight[i] - smallerFromLeft[i]-1;
        ans = max(ans, width*arr[i]);
    }

    return ans;
}
