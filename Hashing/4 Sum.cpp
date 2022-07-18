vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    
    int n = A.size();
    for(int i=0; i<A.size(); i++){
        for(int j=i+1; j<A.size(); j++){
            int low = j+1, high = A.size()-1, target = B-A[i]-A[j];
            while(low < high){
                if(A[low] + A[high] < target){
                    low++;
                }
                else if(A[low] + A[high] == target){
                    ans.push_back({A[i], A[j], A[low], A[high]});
                    low++, high--;
                    while(low < high && A[low] == A[low-1])
                        low++;
                    while(low < high && A[high] == A[high+1])
                        high--;
                }
                else{
                    high--;
                }
            }
            while(j+1<n && A[j] == A[j+1])
                j++;    
        }
        while(i+1<n && A[i] == A[i+1])
            i++;
    }
    
    return ans;
}
