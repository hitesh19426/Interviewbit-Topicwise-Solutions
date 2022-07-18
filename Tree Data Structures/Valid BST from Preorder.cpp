int Solution::solve(vector<int> &preorder) {
    stack<int> stack;
    int root = INT_MIN;

    for(int val: preorder){
        if(val < root)
            return false;

        while(not stack.empty() && stack.top() < val){
            root = stack.top();
            stack.pop();
        }
        stack.push(val);
    }

    return true;
}
