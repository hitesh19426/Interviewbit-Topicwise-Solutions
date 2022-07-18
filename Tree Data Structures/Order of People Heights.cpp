vector<int> bit;

void add(int i){
    for(++i; i<bit.size(); i+=i&-i)
        bit[i]++;
}

int sum(int i){
    int count = 0;
    for(++i; i>0; i-=i&-i)
        count += bit[i];
    return count;
}

int check_empty_position(int i, int infront){
    int pos = i+1 - sum(i);
    return pos>=infront;
}

int position(vector<int>& ans, int infront){
    int low = 0, high = ans.size()-1, pos = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(check_empty_position(mid, infront+1))
            pos = mid, high = mid-1;
        else
            low = mid+1;
    }
    return pos;
}

vector<int> Solution::order(vector<int> &height, vector<int> &infront) {
    vector<pair<int, int>> arr;
    for(int i=0; i<height.size(); i++){
        arr.push_back({height[i], infront[i]});
    }
    sort(arr.begin(), arr.end());

    vector<int> ans(arr.size(), -1);
    bit.assign(arr.size()+1, 0);

    for(int i=0; i<arr.size(); i++){
        int pos = position(ans, arr[i].second);
        ans[pos] = arr[i].first;
        add(pos);
    }

    return ans;
}
