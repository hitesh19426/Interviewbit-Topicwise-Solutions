int Solution::solve(vector<int> &arr, int b) {
    vector<int> lights;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 1){
            lights.push_back(i);
        }
    }

    vector<int> selected;
    for(int i=0; i<arr.size(); i++){
        int j;
        for(j = lights.size()-1; j>=0; j--){
            if(lights[j]-b+1 <= i and i <= lights[j]+b-1){
                selected.push_back(lights[j]);
                break;
            }
        }
        if(j == -1)
            return -1;
        i = selected.back()+b-1;
    }

    return selected.size();
}
