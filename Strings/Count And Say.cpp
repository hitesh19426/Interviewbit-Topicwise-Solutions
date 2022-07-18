string Solution::countAndSay(int A) {
    string s = "1";
    while(--A){
        string next = "";
        char last = s[0];
        int count = 0;
        for(char c:s){
            if(c == last){
                count++;
            }
            else{
                next += to_string(count) + last;
                count = 1;
                last = c;
            }
        }
        next += to_string(count) + last;
        s = next;
    }
    return s;
}
