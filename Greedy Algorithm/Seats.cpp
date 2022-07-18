int Solution::seats(string s) {
    vector<int> arr;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'x')
            arr.push_back(i);
    }

    if(arr.empty())
        return 0;

    int center = (arr.size()&1 ? arr[arr.size()/2] : (arr[arr.size()/2] + arr[(arr.size()-1)/2])/2 );
    int mid = (arr.size()&1 ? arr.size()/2 : (arr.size()-1)/2);

    long long mod = 10000003, ans = 0, target = center;
    for(int i=mid; i>=0; i--){
        ans += target-arr[i];
        ans %= mod;
        target--;
    }

    target = center+1;
    for(int i=mid+1; i<arr.size(); i++){
        ans += arr[i]-target;
        ans %= mod;
        target++;
    }

    return ans;
}
