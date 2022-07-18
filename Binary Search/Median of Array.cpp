double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size(), n = B.size(), target = (m+n+1)/2;
    if(A.size() > B.size())
        return findMedianSortedArrays(B, A);

    bool isOdd = ((m+n)&1);
    int low = 0, high = m;
    while(low <= high){
        int mid = low + (high-low)/2;
        int i = mid, j = target-i;

        if(j>0 && i<m &&  A[i] < B[j-1] ){
            low = mid+1;
        }
        else if( i>0 && j<n &&  A[i-1] > B[j] ){
            high = mid;
        }
        else{
            double leftMax, rightMin;
            if(i==0)
                leftMax = B[j-1];
            else if(j==0)
                leftMax = A[i-1];
            else
                leftMax = max(A[i-1], B[j-1]);

            if(isOdd)
                return leftMax;

            if(i == m)
                rightMin = B[j];
            else if(j==n)
                rightMin = A[i];
            else
                rightMin = min(A[i], B[j]);
            return ( leftMax + rightMin )/2.0;
        }
    }

    return -1;
}