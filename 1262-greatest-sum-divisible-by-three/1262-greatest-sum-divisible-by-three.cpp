class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        // Bottom-Up Approach space optimization

        int n =  nums.size();

        //vector<vector<int>> dp(2, vector<int>(3,-1));

        vector<int> dp = {0, INT_MIN, INT_MIN};

        vector<int> new_dp(3);


        // // BASE CASES

        // dp[1][0] = 0;

        // dp[1][1] = INT_MIN; 

        // dp[1][2] = INT_MIN;


        // Filling the Matrix


        for(int i=n-1; i>=0; i--){

            fill(new_dp.begin(), new_dp.end(), INT_MIN);
 

            for(int rem=0; rem<3; rem++){

                // take

                int newRem = (nums[i] + rem)%3;

                int take =  nums[i] +  dp[newRem];
                


                // skip
            
                int skip = dp[rem];

                new_dp[rem] = max(take,skip);

            }

            dp = new_dp;
        }

        return dp[0];

        
        
    }
};