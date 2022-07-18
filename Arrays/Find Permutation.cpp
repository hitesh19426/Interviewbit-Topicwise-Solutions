vector<int> Solution::findPerm(const string s, int b) {
    int mini = 1, maxi = 1;
    vector<int> ans{1};
    for(char c: s){
        if(c == 'I'){
            ans.push_back(maxi+1);
            maxi++;
        }
        else{
            ans.push_back(mini-1);
            mini--;
        }
    }

    int increase = 1-mini;
    for(int &x: ans){
        x+=increase;
    }
    return ans;
}
