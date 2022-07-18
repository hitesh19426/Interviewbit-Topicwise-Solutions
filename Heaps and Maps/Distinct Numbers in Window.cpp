vector<int> Solution::dNums(vector<int> &A, int B) {
    if(B>A.size())
        return {};
    unordered_map<int, int> count;
    for(int i=0; i<B; i++)
        count[A[i]]++;

    vector<int> ans;
    for(int i=0; i+B-1<A.size(); i++){
        if(i!=0){
            count[A[i-1]]--;
            if(count[A[i-1]] == 0)
                count.erase(A[i-1]);
            count[A[i+B-1]]++;
        }

        ans.push_back(count.size());
    }

    return ans;
}
