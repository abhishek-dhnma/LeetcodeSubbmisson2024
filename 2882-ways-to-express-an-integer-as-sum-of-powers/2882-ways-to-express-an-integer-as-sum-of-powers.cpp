class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int n, int nums, int x, vector<vector<int>> & dp) {
        // Base cases
        if (n == 0) {
            return 1; // Found a valid combination
        }
        if (n < 0) {
            return 0; // Invalid: sum cannot be negative
        }
        int currPower = pow(nums, x);
        if (currPower > n) {
            return 0; // Current number's x-th power is too large
        }

        // Check memoized result
        if (dp[n][nums] != -1) {
            return dp[n][nums];
        }

        // Recursive cases
        int take = solve(n - currPower, nums + 1, x, dp); // Include nums^x
        int skip = solve(n, nums + 1, x, dp);            // Skip nums^x

        return dp[n][nums] = (take + skip) % mod; // Store and return result
    }

    int numberOfWays(int n, int x) {
        int nums = 1;
        dp.resize(301, vector<int>(301, -1)); // Initialize DP table
        return solve(n, nums, x, dp);
    }
};