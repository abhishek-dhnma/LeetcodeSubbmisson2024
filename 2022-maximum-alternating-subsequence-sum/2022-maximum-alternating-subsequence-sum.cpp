class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        // Bottom Up --> past answers se apna -> future ka solution banate hai

        

        int n = nums.size();

        vector<vector<long long>> dp(n+1, vector<long long>(2,0)); // even : 0 and odd : 1 and size n+1 liya h

        // 1-based indexing 

        for(int i=1; i<=n; i++){
            
            // even case
            dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]);

            // odd case
            dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]);
        }

        return max(dp[n][0],dp[n][1]);

       // TC : O(N)
       // SC : O(N)
        
    }
};