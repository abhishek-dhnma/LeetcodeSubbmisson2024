class Solution {
public:

    vector<int> dp;

    int solve(vector<int>& nums,int n, int i){

        // base cases

        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        // take 
        
        int take = nums[i] + solve(nums,n, i+2);


        int nottake = solve(nums, n, i+1);


        return dp[i] =  max( take, nottake );

    }


    int rob(vector<int>& nums) {

        int n = nums.size();


        dp = vector<int>(101, -1);

        return solve(nums, n, 0);
    }
};