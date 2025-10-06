class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        // Bottom Up --> past answers se apna -> future ka solution banate hai

        long long dp[1000001][2];

        int n = nums.size();

        for(int i=1; i<n+1; i++){
            
            // even case
            dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]);

            // odd case
            dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]);
        }

        return max(dp[n][0],dp[n][1]);
        
    }
};