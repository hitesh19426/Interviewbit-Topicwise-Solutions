vector<int> Solution::equal(vector<int> &arr) {
    unordered_map<int, pair<int, int>> map;
    int n = arr.size();
    
    vector<int> ans{n, n, n, n};
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(map.find(arr[i]+arr[j]) == map.end()){
                map[arr[i]+arr[j]] = {i, j};
                continue;
            }
            
            auto &[first, second] = map[arr[i]+arr[j]];
            if(i == first || i == second || j == first || j == second)
                continue;
            
            ans = min(ans, {first, second, i, j});
        }
    }
    
    return ans;
}
/*
"Brute Force: Use 4 loops to loop over each qradruple and find the ones satisfying the conditions.

Brute Force optimized: Use 3 loops and loop for the final value using cache. Try this also, I am not sure how to implement this.

Current Approach: Let us go over each pair and find their sum. Then you need to find the smallest pairs from same sum st their indexes are different. 
This tells us that we need to group some ""information"" about pairs wrt sum, and then look into each sum bucket to find the answer.

What information to store for each bucket? You basically need to store every pair whose sum belong to that bucket. 
Then you need to look at indexes in pairs st both their indexes are different. Now, here is a problem. Suppose all values are equal. 
Then their sum are equal. So each pair will go to same sum bucket. This means you have n*n pairs. Now you need to find 2 smallest pairs with no matching indexes. 
One way is sorting and then two pointers, other is using set. Both of which will cost n*nlogn*n time.

So how to tackle this? One way is to maintain 2 things for each sum. 1) Individual index pairs and 2) all the seen indexes.
Before inserting any pair, just check whether any of that index is already seen. If yes, skip that pair. Otherwise mark both index as seen and insert that pair.

Time Complexity = Since each pair can be inserted only once in a bucket, there can be at most n insertion in a bucket. So maximum insertion time is logn. n*n insertion will take n*n*logn time.

After that, we go over each bucket (containing max n pairs of index), and get first 2 pairs. In worst case, there are n*n sums and so we look at n*n buckets. 
Finding first 2 pairs is constant time opearation. So overall n*n.

Total Time = n*n*logn + n*n = n*n*logn"


Most optimized Approach: The idea is to optimize above approach. How? One thing to note is that for each set, you need need first 2 values. 
So one optimization can be to maintain size at 2 like in pq. Another is that you are scanning the pairs in lexographical order only. So first pair will be 
smallest, second will be second smallest and so on. So actually you only need the first ever pair and not whole bucket.

This means you can store first ever pair for all sum, and as soon as you get second pair with all different vertices, you have your second pair and can
update the final answer.

Time Complexity: n*n
*/