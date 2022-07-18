void getab(stack<int>& stack, int &a, int &b){
    a = stack.top(); stack.pop();
    b = stack.top(); stack.pop();
}

int Solution::evalRPN(vector<string> &A) {
    if(A.empty())
        return 0;
    
    int a = 0, b = 0;
    stack<int> stack;
    
    for(string &str: A){
        if(str == "+"){
            getab(stack, a, b);
            stack.push(b+a);
        }
        else if(str == "-"){
            getab(stack, a, b);
            stack.push(b-a);
        }
        else if(str == "*"){
            getab(stack, a, b);
            stack.push(b*a);
        }
        else if(str == "/"){
            getab(stack, a, b);
            stack.push(b/a);
        }
        else{
            stack.push(stoi(str));
        }
    }

    return stack.top();
}