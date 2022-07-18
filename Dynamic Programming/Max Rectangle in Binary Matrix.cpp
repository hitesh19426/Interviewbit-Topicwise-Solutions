int Solution::maximalRectangle(vector<vector<int> > &arr) {
    int m = arr.size(), n = arr[0].size();
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1){
                arr[i][j] += arr[i-1][j];
            }
        }
    }

    int ans = 0;
    for(auto& row: arr){
        int smallerFromLeft[n], smallerFromRight[n];
        for(int i=0; i<n; i++){
            int left = i-1;
            while(left >=0 && row[left] >= row[i])
                left = smallerFromLeft[left];
            smallerFromLeft[i] = left;
        }

        for(int i=n-1; i>=0; i--){
            int right = i+1;
            while(right <n && row[right] >= row[i])
                right = smallerFromRight[right];
            smallerFromRight[i] = right;
        }

        for(int i=0; i<n; i++){
            int base = smallerFromRight[i] - smallerFromLeft[i] - 1;
            int height = row[i];
            ans = max(ans, base*height);
        }
    }

    return ans;
}
