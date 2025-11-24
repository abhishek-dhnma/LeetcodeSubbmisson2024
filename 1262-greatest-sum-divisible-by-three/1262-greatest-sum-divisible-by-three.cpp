class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        // Bottom-Up Approach space optimization

        int n = nums.size();

        vector<int> dp = {0, INT_MIN, INT_MIN};

        vector<int> new_dp(3);

        // Filling

        for (int i = n - 1; i >= 0; i--) {

            fill(new_dp.begin(), new_dp.end(), INT_MIN);

            for (int rem = 0; rem < 3; rem++) {

                // take

                int newRem = (nums[i] + rem) % 3;

                int take = nums[i] + dp[newRem];

                // skip

                int skip = dp[rem];

                new_dp[rem] = max(take, skip);
            }

            dp = new_dp;
        }

        return dp[0];
    }
};