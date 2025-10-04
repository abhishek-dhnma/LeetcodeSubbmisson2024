class Solution {
public:
    int n;

   long long dp[1000001][2];


    long long solve(int i, vector<int>& nums, bool flag) {

        if (i >= n)
            return 0;

        if(dp[i][flag] != -1){
            return dp[i][flag];
        }

        long long skip = solve(i + 1, nums, flag);

        int val = nums[i];
        if (flag == false) {
            val = -val;
        }

        long long take = solve(i + 1, nums, !flag) + val;

        return dp[i][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {

        n = nums.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, nums, true);
    }
};