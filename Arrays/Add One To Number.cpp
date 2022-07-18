vector<int> Solution::plusOne(vector<int> &A) {
    reverse(A.begin(), A.end());
    int carry = 1;
    for(int i=0; i<A.size(); i++){
        int sum = A[i]+carry;

        A[i] = sum%10;
        carry = sum/10;
    }
    if(carry == 1)
        A.push_back(1);
    while(!A.empty() && A.back() == 0)
        A.pop_back();
    reverse(A.begin(), A.end());
    return A;
}
