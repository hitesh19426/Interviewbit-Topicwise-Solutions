string Solution::convert(string A, int B) {
    string row[B];
    for(int i=0; i<B; i++)
        row[i] = "";
    
    int i = 0;
    while(i<A.size()){
        int j = 0;
        while(j<B && i<A.size()){
            row[j++] += A[i++];
        }
        j = B-2;
        while(j>0 && i<A.size()){
            row[j--] += A[i++];
        }
    }

    string ans = "";
    for(auto &str: row)
        ans += str;

    return ans;
}
