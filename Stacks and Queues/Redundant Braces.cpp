int Solution::braces(string A) {
    stack<char> stack;
    for(int i=0; i<(int)A.size(); i++){
        if(A[i] != ')'){
            stack.push(A[i]);
        }
        else{
            int count = 0;
            while(not stack.empty() && stack.top() != '('){
                stack.pop();
                count++;
            }
            if(count <= 1)
                return 1;
            stack.pop();
        }
    }

    return 0;
}
