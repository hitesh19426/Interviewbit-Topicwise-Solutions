int Solution::mice(vector<int> &mouses, vector<int> &holes) {
    sort(holes.begin(), holes.end());
    sort(mouses.begin(), mouses.end());

    int ans = 0;
    for(int i=0; i<holes.size(); i++){
        ans = max(ans, abs(holes[i]-mouses[i]));
    }

    return ans;
}
