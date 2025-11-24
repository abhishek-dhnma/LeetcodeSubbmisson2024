class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        // Bottom-Up Approach

        int n =  nums.size();

        vector<vector<int>> dp(n+1, vector<int>(3,-1));


        dp[n][0] = 0;

        dp[n][1] = INT_MIN; 

        dp[n][2] = INT_MIN;


        for(int i=n-1; i>=0; i--){
            for(int rem=0; rem<3; rem++){
                

                int newRem = (nums[i] + rem)%3;
                int take = nums[i] +  dp[i+1][newRem];

                int skip = dp[i+1][rem];


                dp[i][rem] = max(take, skip);


            }
        }

        return dp[0][0];

        
        
    }
};