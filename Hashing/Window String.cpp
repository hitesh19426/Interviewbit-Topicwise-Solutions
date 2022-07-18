string Solution::minWindow(string A, string B) {
    unordered_map<char, int> count;
    for(char c: B)
        count[c]++;

    int i = 0, j = 0, length = INT_MAX, start = -1, remaining = count.size();
    while(j < A.size()){
        // expand the window
        if(count.find(A[j]) != count.end()){
            count[A[j]]--;
            if(count[A[j]]==0) remaining--;
        }

        // unexpand the window
        while(remaining == 0 && i <= j){
            if(count.find(A[i]) != count.end()){
                if(!count[A[i]]) remaining++;
                count[A[i]]++;
            }
                
            if(j-i+1 < length){
                length = j-i+1;
                start = i;
            }
            i++;
        }
        j++;
    }

    return start == -1 ? "" : A.substr(start, length);
}
