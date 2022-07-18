vector<int> Solution::stepnum(int a, int b) {
    queue<int> queue;
    for(int i=1; i<10; i++){
        queue.push(i);
    }
    
    vector<int> ans;
    if(a == 0)
        ans.push_back(0);
    while(!queue.empty()){
        auto num = queue.front();
        queue.pop();
        
        if(num >= a)
            ans.push_back(num);
        int digit = num%10;
        if(digit != 0 && 10*num+digit-1 <= b)
            queue.push(10*num + digit-1);
        if(digit != 9 && 10*num+digit+1 <= b)
            queue.push(10*num + digit+1);
    }
    
    return ans;
}
