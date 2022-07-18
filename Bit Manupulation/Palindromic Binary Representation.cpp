int binary_string_to_int(string &s){
    int ans = 0;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == '1')
            ans += (1<<i);
    }
    return ans;
}
int Solution::solve(int n) {
    if(n == 1)
        return 1;
    n--;
    queue<string> queue;
    queue.push("11");

    while(not queue.empty()){
        auto current = queue.front();
        queue.pop();
        n--;

        if(n==0){
            return binary_string_to_int(current);
        }

        int mid = current.size()/2;
        if( current.size()%2 == 1 ){
            current.insert(mid, 1, current[mid]);
            queue.push(current);
        }
        else{
            string first = current;
            first.insert(mid, 1, '0');
            current.insert(mid, 1, '1');
            queue.push(first);
            queue.push(current);
        }
    }

    return 0;
}
