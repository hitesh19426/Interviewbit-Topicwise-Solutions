vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    if(B > (int)A.size())
        return {*max_element(A.begin(), A.end())};
    
    deque<int> list;
    vector<int> arr;

    for(int i=0; i<B; i++){
        while(!list.empty() && A[list.back()] <= A[i])
            list.pop_back();
        list.push_back(i);
    }

    for(int i=0; i<(int)A.size()-B+1; i++){
        if(i!=0){
            while(!list.empty() && A[list.back()] <= A[i+B-1])
                list.pop_back();
            list.push_back(i+B-1);
        }

        while(!list.empty() && list.front() < i)
            list.pop_front();
        arr.push_back(A[list.front()]);
    }

    return arr;
}
