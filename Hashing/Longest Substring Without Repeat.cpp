int Solution::lengthOfLongestSubstring(string A) {
    vector<int> count(256, 0);
    int start = 0, end = 0, length = 0;
    while(end < A.size()){
        count[A[end]]++;

        while(count[A[end]]>1 && start<=end){
            count[A[start]]--;
            start++;
        }

        end++;
        length = max(length, end-start);
    }

    return length;
}
