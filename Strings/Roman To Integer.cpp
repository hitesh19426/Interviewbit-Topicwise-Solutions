const int values[] = {1, 5, 10, 50, 100, 500, 1000};

int Solution::romanToInt(string A) {
    if(A.empty())
        return 0;

    unordered_map<char, int> index = { {'I', 0}, {'V', 1}, {'X', 2}, {'L', 3}, {'C', 4}, {'D', 5}, {'M', 6}};

    int ans = 0;
    for(int i=0; i<A.size(); i++){
        ans += values[index[A[i]]];
        if(i!=0 && index[A[i-1]] < index[A[i]]){
            ans -= 2*values[index[A[i-1]]];
        }
    }
    return ans;
}
