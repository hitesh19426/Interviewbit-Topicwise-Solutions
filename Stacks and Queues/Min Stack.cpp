stack<int> st, min_values;
MinStack::MinStack() {
    while(not st.empty())
        st.pop();
    while(not min_values.empty())
        min_values.pop();
}

void MinStack::push(int x) {
    st.push(x);
    int to_push = (min_values.empty() ? x : min(min_values.top(), x));
    min_values.push(to_push);
}

void MinStack::pop() {
    if(st.empty())
        return;
    st.pop();
    min_values.pop();
}

int MinStack::top() {
    if(st.empty())
        return -1;
    return st.top();
}

int MinStack::getMin() {
    if(st.empty())
        return -1;
    return min_values.top();
}

