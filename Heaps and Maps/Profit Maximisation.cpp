int Solution::solve(vector<int> &A, int B) {
    priority_queue<int> maxheap;
    for(int a:A)
        maxheap.push(a);

    int ans = 0;
    while(B-- && !maxheap.empty()){
        ans += maxheap.top();
        if(maxheap.top())
            maxheap.push(maxheap.top()-1);
        maxheap.pop();
    }

    return ans;
}
