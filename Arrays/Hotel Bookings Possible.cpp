bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());

    int i = 0, j = 0, count = 0, max_count = 0, n = arrive.size();
    while(i<n){
        if(arrive[i] < depart[j]){
            count++;
            max_count = max(max_count, count);
            if(max_count > k)
                return false;
            i++;
        }
        else{
            count--;
            j++;
        }
    }

    return true;
}
