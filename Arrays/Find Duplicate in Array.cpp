int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size()-1, sq = ceil(sqrt(n)), no = ceil((double)n/sq);
    vector<int> count(no, 0);

    for(int x: A){
        count[(x-1)/sq]++;
    }

    int ind = -1;
    for(int i=0; i<count.size(); i++){
        int low = i*sq+1;
        int high = min(n, sq*(i+1));
        int capacity = high-low+1;

        if(count[i] > capacity){
            ind = i;
            break;
        }
    }

    if(ind == -1)
        return -1;

    unordered_set<int> uset;
    for(int x: A){
        if((x-1)/sq == ind){
            if(uset.find(x) == uset.end())
                uset.insert(x);
            else
                return x;
        }
    }

    return -1;
}