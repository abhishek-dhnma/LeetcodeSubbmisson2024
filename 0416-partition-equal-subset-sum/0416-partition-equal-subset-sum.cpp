class Solution {
public: 

    bool solve(int i, int target, vector<int> & nums,  vector<vector<int>> & dp ){

        if(target == 0) return true;

        // BASE CASE

        if(i == nums.size() || target < 0){
    
            return false;

        }

        if(dp[i][target] != -1) return dp[i][target];

        int take = (solve(i+1, target - nums[i], nums, dp));
        int notTake = (solve(i+1, target, nums, dp));


        return dp[i][target] = take || notTake;
    }


    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        if(sum%2 != 0) return false;


        int target = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

    return solve(0, target, nums, dp);

    }
};