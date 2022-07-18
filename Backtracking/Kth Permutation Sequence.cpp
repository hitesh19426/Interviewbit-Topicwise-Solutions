int by_factorial(int k, int n){
    int factorial = 1;
    while(n){
        factorial *= n--;
        if(factorial > k)
            return 0;
    }
    return k/factorial;
}

int mod_factorial(int k, int n){
    int factorial = 1;
    while(n){
        factorial *= n--;
        if(factorial > k)
            return k;
    }
    return k%factorial;
}

string solve(vector<int>& arr, int n, int k){
    if(n == 1)
        return to_string(arr[0]);

    int group = by_factorial(k, n-1), position = mod_factorial(k, n-1);

    string ans = to_string(arr[group]);
    arr.erase(find(arr.begin(), arr.end(), arr[group]));
    ans += solve(arr, n-1, position);

    return ans;
}

string Solution::getPermutation(int A, int B) {
    vector<int> arr;
    for(int i=1; i<=A; i++)
        arr.push_back(i);
    return solve(arr, A, B-1);
}
