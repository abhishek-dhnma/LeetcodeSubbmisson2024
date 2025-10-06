class Solution {
public:
    int n;
    int solve(vector<int>& nums, int  startidx, int  previousElmtidx, vector<vector<int>>& dp) {

        // base case
        if (startidx >= n) {
            return 0;
            // out of bound
        }

        if( previousElmtidx != -1 && dp[startidx][previousElmtidx]  != -1){
            return dp[startidx][previousElmtidx];
        }

        // recursive case
        int take = 0;
        if (previousElmtidx == -1 || nums[previousElmtidx] < nums[startidx]) {
            take = 1 + solve(nums, startidx + 1, startidx, dp);
        }

        int skip = solve(nums, startidx + 1, previousElmtidx, dp);
        if(previousElmtidx != -1 ){
            dp[startidx][previousElmtidx] = max(take, skip);
        }

        return  max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        int startidx = 0;
        n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(nums, startidx, -1, dp);
    }
};