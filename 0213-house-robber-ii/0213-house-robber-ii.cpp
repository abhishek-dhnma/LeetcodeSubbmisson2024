class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int i, int n) {

        if (i > n) {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];
        // take
        int take = nums[i] + solve(nums, i + 2, n);

        // skip

        int skip = solve(nums, i + 1, n);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        dp = vector<int>(n , -1);

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int takeO = solve(nums, 0, n - 2);

        fill(dp.begin(), dp.end(), -1);
        int notakeO = solve(nums, 1, n-1);

        return max(takeO, notakeO);
    }
};