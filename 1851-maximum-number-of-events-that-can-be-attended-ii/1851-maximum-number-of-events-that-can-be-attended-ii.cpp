class Solution {
    int binarySearch(vector<vector<int>>& events, int currEnd, int startIdx) {
    int low = startIdx, high = events.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (events[mid][0] > currEnd)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
public:

    int n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& events, int i, int k){
    
    if(i >= n || k ==0 ){
        return 0;
    }

    if(dp[i][k] != -1){
        return dp[i][k];
    }

    int end = events[i][1];
    int val = events[i][2];
    // Skip current event
    int skip = solve(events, i+1, k);
    int nextIndex = binarySearch(events, end, i + 1);
    
    // Take current event
    int take = val + solve(events, nextIndex, k-1);

    return dp[i][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end());  // Sort by start time
        n = events.size();
        dp.resize(n+1, vector<int>(k+1, -1));
        return solve(events, 0, k);
    }
};