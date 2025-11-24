class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        // Bottom-Up Approach

        int n =  nums.size();

        //vector<vector<int>> dp(2, vector<int>(3,-1));

        vector<int> next = {0, INT_MIN, INT_MIN};

        vector<int> cur(3);


        // // BASE CASES

        // dp[1][0] = 0;

        // dp[1][1] = INT_MIN; 

        // dp[1][2] = INT_MIN;


        // Filling the Matrix


        for(int i=n-1; i>=0; i--){

            fill(cur.begin(), cur.end(), INT_MIN);

            int x = nums[i];
            int r = x % 3;

            for(int rem=0; rem<3; rem++){

                // take

                int newRem = (r + rem)%3;

                if(next[newRem] != INT_MIN){
                    cur[rem] = max(cur[rem] ,x+  next[newRem]);
                }


                // skip
            
                cur[rem] = max(cur[rem], next[rem]);

            }

            next = cur;
        }

        return next[0];

        
        
    }
};