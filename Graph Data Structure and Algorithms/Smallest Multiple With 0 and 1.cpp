string Solution::multiple(int n) {
    if(n == 1)
        return "1";
    queue<int> queue;
    int vis[n+5], parent[n+5], value[n+5];
    memset(vis, 0, sizeof(vis));
    memset(parent, 0, sizeof(parent));
    memset(value, 0, sizeof(value));
    
    queue.push(1);
    vis[1] = 1;
    parent[1] = -1;
    value[1] = 1;
    
    while(!queue.empty()){
        int num = queue.front();
        queue.pop();
        
        if(num == 0){
            string res = "";
            while(num != -1){
                res += ('0'+value[num]);
                num = parent[num];
            }
            reverse(res.begin(), res.end());
            return res;
        }
        
        int num1 = (10*num)%n, num2 = (10*num+1)%n;
        if(!vis[num1]){
            queue.push(num1);
            vis[num1] = true;
            parent[num1] = num;
            value[num1] = 0;
        }
        
        if(!vis[num2]){
            queue.push(num2);
            vis[num2] = true;
            parent[num2] = num;
            value[num2] = 1;
        }
    }
    
    return "";
}
