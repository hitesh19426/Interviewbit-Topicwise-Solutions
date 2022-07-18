int Solution::solve(string s, int k) {
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    int ind = 0;
    for(int i=0; i<7; i++){
        if(days[i] == s){
            ind = i;
            break;
        }
    }
    
    int ans = k/7;
    k %= 7;
    
    return ans + bool((ind+k-1)>=6);
    
}
