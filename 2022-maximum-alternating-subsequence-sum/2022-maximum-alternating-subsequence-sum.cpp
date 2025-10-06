class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // guard if empty input

        // dp[i][0] -> best alternating-sum considering nums[0..i] and the last operation is '-' (flag = 0)
        // dp[i][1] -> best alternating-sum considering nums[0..i] and the last operation is '+' (flag = 1)
        // We consider subsequences, not necessarily contiguous.
        vector<vector<long long>> dp(n, vector<long long>(2, 0));

        // Base:
        // Can't end with '-' at i=0 since there's no prior '+', so dp[0][0] = 0 (equivalent to not taking anything)
        dp[0][0] = 0;
        // Ending with '+' at i=0 means take nums[0]
        dp[0][1] = nums[0];

        for (int i = 1; i < n; ++i) {
            // If we want the best that ends with '-' at i:
            // either keep previous '-' (don't take nums[i]) OR take nums[i] as a '-' after a previous '+'
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - (long long)nums[i]);

            // If we want the best that ends with '+' at i:
            // either keep previous '+' (don't take nums[i]) OR take nums[i] as a '+' after a previous '-'
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + (long long)nums[i]);
        }

        // Answer is best alternating-sum that ends with a '+'
        return dp[n-1][1];
    }
};
