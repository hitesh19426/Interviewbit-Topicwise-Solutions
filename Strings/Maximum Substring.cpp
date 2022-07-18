int Solution::solve(string s, int B) {
    int b = 0, ans = 0;
    for(int i=0; i<s.size(); i+=B){
        int a = 0;
        for(int j=i; j<min((int)s.size(), i+B); j++){
            if(s[j] == 'a')
                a++;
        }
        ans = max(a, ans);
    }
    return ans;
}
