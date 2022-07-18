int Solution::compareVersion(string A, string B) {
    int i = 0, j = 0;
    while(i < A.length() && j < B.length()){
        string versionA = "", versionB = "";

        while(i<A.length() && A[i] == '0')
            i++;
        while(i<A.length() && A[i] != '.')
            versionA += A[i++];

        while(j<B.length() && B[j] == '0')
            j++;
        while(j<B.length() && B[j] != '.')
            versionB += B[j++];

        if(versionA != versionB){
            if( versionA.length() != versionB.length())
                return versionA.length() > versionB.length() ? 1 : -1;
            return versionA < versionB ? -1 : 1;
        }
        
        i++, j++;
    }

    while(i < A.length()){
        if(A[i]>'0' && A[i]<='9')
            return 1;
        i++;
    }
    while(j < B.length()){
        if(B[j]>'0' && B[j]<='9')
            return -1;
        j++;
    }
    
    return 0;
}
