class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int rem, vector<int>& nums){
        if(i >= nums.size()){
            return (rem == 0) ? 0 : INT_MIN;
        }

        if(dp[i][rem] != -1){
            return dp[i][rem];
        }

        // safe: ask child first
        int childTake = solve(i+1, (rem + nums[i]) % 3, nums);
        int take = (childTake == INT_MIN) ? INT_MIN : nums[i] + childTake;

        int skip = solve(i+1, rem, nums);

        return dp[i][rem] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(3, -1));
        int ans = solve(0, 0, nums);
        return max(0, ans); // ensure non-negative
    }
};
