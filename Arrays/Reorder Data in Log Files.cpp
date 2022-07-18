bool comparator(const string &a, const string &b){
    int inda = a.find('-');
    string words_a = a.substr(inda+1);
    string identifier_a = a.substr(0, inda);
    
    int indb = b.find('-');
    string words_b = b.substr(indb+1);
    string identifier_b = b.substr(0, indb);

    if(words_a != words_b)
        return words_a < words_b;
    return identifier_a < identifier_b;
}

vector<string> Solution::reorderLogs(vector<string> &arr) {
    vector<string> letter_logs, digit_logs;
    for(int i=0; i<arr.size(); i++){
        bool is_log_letter = isalpha(arr[i].back());
        if(is_log_letter){
            letter_logs.push_back(arr[i]);
        }
        else{
            digit_logs.push_back(arr[i]);
        }
    }

    sort(letter_logs.begin(), letter_logs.end(), comparator);
    
    for(auto &log: digit_logs){
        letter_logs.push_back(log);
    }
    
    return letter_logs;
}
