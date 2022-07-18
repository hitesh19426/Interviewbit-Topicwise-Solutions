vector<int> Solution::prevSmaller(vector<int> &arr) {
    int n = arr.size();
    vector<int> smallerFromLeft(n);

    for(int i=0; i<n; i++){
        int left = i-1;
        while(left >=0 && arr[left] >= arr[i])
            left = smallerFromLeft[left];
        smallerFromLeft[i] = left;
    }

    for(int i=0; i<n; i++){
        if(smallerFromLeft[i] != -1)
            smallerFromLeft[i] = arr[smallerFromLeft[i]];
    }

    return smallerFromLeft;
}
