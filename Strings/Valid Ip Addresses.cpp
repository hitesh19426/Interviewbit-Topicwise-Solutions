vector<string> Solution::restoreIpAddresses(string A) {
    if(A.size()<4 || A.size()>12)
        return {};

    vector<string> ips;
    int first = 0, second = 0, third = 0, fourth = 0; // numbers
    string firsts = "", seconds = "", thirds = "", fourths = "";    // strings
    for(int i=0; i<3; i++){
        first = 10*first + (A[i]-'0');
        firsts += A[i];

        if(first>255 || (firsts.size()>1 && firsts[0]=='0'))
            break;

        second = 0; seconds = "";
        for(int j=i+1; j<=i+3 && j<A.size(); j++){
            second = 10*second + (A[j]-'0');
            seconds += A[j];

            if(second>255 || (seconds.size()>1 && seconds[0]=='0'))
                break;

            third = 0; thirds = "";
            for(int k=j+1; k<=j+3 && k<A.size(); k++){
                third = 10*third + (A[k]-'0');
                thirds += A[k];

                if(third>255 || (thirds.size()>1 && thirds[0]=='0'))
                    break;

                fourths = A.substr(k+1);
                if(fourths.empty())
                    break;
                if(stoi(fourths)>255 || (fourths.size()>1 && fourths[0]=='0'))
                    continue;
                ips.push_back(firsts+'.'+seconds+'.'+thirds+'.'+fourths);
            }
        }
    }

    return ips;
}
