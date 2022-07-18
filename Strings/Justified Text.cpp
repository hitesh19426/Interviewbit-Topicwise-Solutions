string justify(vector<string> arr, int start, int end, int maxWidth, int sum, bool lastline=false){
    if(start == end){
        return arr[start] + string(maxWidth-sum, ' ');
    }

    int places = end-start, gaps = maxWidth-sum, evenly = (lastline ? 0 : gaps/places), biased = gaps%places;
    string ans = "";
    for(int i=start; i<end; i++){
        ans += arr[i] + string(evenly + (biased-->0 || lastline ? 1 : 0), ' ');
    }
    ans += arr[end];
    ans += string(maxWidth-(int)ans.size(), ' ');

    return ans;
}

vector<string> Solution::fullJustify(vector<string> &arr, int maxWidth) {
    if(arr.empty())
        return {};
    
    int start = 0, sum = 0;
    vector<string> ans;
    for(int i=0; i<arr.size(); i++){
        if(arr[i].empty())
            continue;
        if(sum + arr[i].size() + i-start > maxWidth){
            auto res = justify(arr, start, i-1, maxWidth, sum);
            ans.push_back(res);

            start = i, sum = arr[i].size();
        }
        else{
            sum += arr[i].size();
        }
    }
    auto res = justify(arr, start, arr.size()-1, maxWidth, sum, true);
    ans.push_back(res);
    
    return ans;
}
