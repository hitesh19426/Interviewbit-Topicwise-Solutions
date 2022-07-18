/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &arr) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(arr.begin(), arr.end(), [](auto &a, auto &b) -> bool {
        return a.start < b.start;
    });

    vector<Interval> ans;
    for(int i=0; i<arr.size(); i++){
        if(ans.empty() || ans.back().end < arr[i].start)
            ans.push_back(arr[i]);
        else
            ans.back().end = max(ans.back().end, arr[i].end);
    }
    return ans;
}
