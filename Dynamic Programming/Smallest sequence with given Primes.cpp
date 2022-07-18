vector<int> Solution::solve(int a, int b, int c, int d) {
    vector<int> arr{a, b, c};
    vector<int> mul(3, 0);

    vector<int> ans;
    while(d--){
        int val = min(arr[0], min(arr[1], arr[2]));
        ans.push_back(val);

        if(val == arr[0]){
            arr[0] = ans[mul[0]] * a;
            mul[0]++;
        }
        if(val == arr[1]){
            arr[1] = ans[mul[1]] * b;
            mul[1]++;
        }
        if(val == arr[2]){
            arr[2] = ans[mul[2]] * c;
            mul[2]++;
        }
    }

    return ans;
}