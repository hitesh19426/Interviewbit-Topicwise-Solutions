vector<int> Solution::maxone(vector<int> &A, int B) {
    int start = 0, end = 0, count = 0, length = 0;
    int onestart = 0, oneend = 0;
    while(end < A.size()){
        if(A[end] == 0){
            count++;
        }

        while(count>B && start<=end){
            if(A[start] == 0){
                count--;
            }
            start++;
        }

        if(end-start+1>length){
            length = end-start+1;
            onestart = start;
            oneend = end;
        }
        end++;
    }
    
    vector<int> ans;
    for(int i=onestart; i<=oneend; i++){
        ans.push_back(i);
    }
    return ans;
}
