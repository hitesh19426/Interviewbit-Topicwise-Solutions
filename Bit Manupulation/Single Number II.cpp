int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    for(int i=0; i<32; i++){
        int count = 0;
        for(int j=0; j<(int)A.size(); j++){
            if(A[j]&(1<<i))
                count++;
        }

        count %= 3;
        ans += count*(1<<i);
    }

    return ans;
}
