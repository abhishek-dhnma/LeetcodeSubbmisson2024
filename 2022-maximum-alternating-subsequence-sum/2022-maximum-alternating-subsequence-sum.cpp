class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        // Bottom Up --> past answers se apna -> future ka solution banate hai

        

        int n = nums.size();

        vector<vector<long long>> dp(n, vector<long long>(2,0)); // even : 1 and odd : 0 and size n liya h

        dp[0][0] = 0;  // flag:false (substract)  - you can't subtract first, so 0
        dp[0][1] = nums[0];   // flag:true (add) 

        for(int i=1; i<n; i++){
            
            // even case
            dp[i][0] = max(dp[i-1][1] - nums[i], dp[i-1][0]);

            // odd case
            dp[i][1] = max(dp[i-1][0] + nums[i], dp[i-1][1]);
        }

        return dp[n-1][1];

       // TC : O(N)
       // SC : O(N)
        
    }
};