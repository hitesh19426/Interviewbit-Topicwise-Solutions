int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), start = 0;

    while(start<n){
        int gas = 0, cost = 0, possible = true;
        for(int move = 0; move<n; move++){
            int position = (start+move)%n;
            gas += A[position];
            cost += B[position];
            if(cost > gas){
                possible = false;
                if(position < start)
                    return -1;
                start = position+1;
                break;
            }
        }
        
        if(possible)
            return start;
    }

    return -1;
}