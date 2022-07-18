void process_directory(vector<string>& stack, string word){
    if(word == "." || word == "")
        return;
    
    if(word == ".."){
        if(not stack.empty())
            stack.pop_back();
        return;
    }
    stack.push_back(word);
}

string Solution::simplifyPath(string A) {
    int start = 0, end = A.find('/');
    string word = "";
    vector<string> stack;

    while(end != -1){
        word = A.substr(start, end-start);
        process_directory(stack, word);

        start = end+1;
        end = A.find('/', start);
    }
    word = A.substr(start, end-start);
    process_directory(stack, word);

    if(stack.empty())
        return "/";

    string ans = "";
    for(string word: stack){
        if(word != "")
            ans += '/' + word;
    }
    return ans;
}
