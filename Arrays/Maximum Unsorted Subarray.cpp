vector<int> Solution::subUnsort(vector<int> &arr) {
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());

    int i = 0, j = arr.size()-1;
    while(arr[i] == temp[i])
        i++;
    while(arr[j] == temp[j])
        j--;

    if(i<j)
        return {i, j};
    return {-1};
}
