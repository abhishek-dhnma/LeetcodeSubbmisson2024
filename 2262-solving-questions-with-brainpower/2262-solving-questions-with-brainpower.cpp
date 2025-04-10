class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        long long next; 
        vector<long long> dp(n+1,0);

        for (int i = n - 1; i >= 0; i--) { // Process from right to left
            int points = q[i][0];
            int skip = q[i][1];
            
            // Take the question and move to `i + skip + 1` (if within bounds)
            long long take = points + (i + skip + 1 < n ? dp[i + skip + 1] : 0);
            
            // Skip this question
            long long notTake = next;

            // Store max result
            dp[i] = max(take, notTake);
            next = dp[i];
        }
        
        return dp[0]; // Start from the first question
    }
};
