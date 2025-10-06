class Solution {
public:
    

    long long dp[1000001][2];


    long long solve(vector<int>& nums, int i, bool flag){


        // base case

        if(i >= nums.size()){
            return 0;
        }
        if(dp[i][flag] != -1){
            return dp[i][flag];
        }


        // recursion

        long long skip = solve(nums,i+1, flag);


        long long take = solve(nums, i+1, !flag) + (flag ? nums[i] : -nums[i]);

  
        return dp[i][flag] = max(skip, take);


    }

    long long maxAlternatingSum(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        return  solve(nums, 0, true);

        // recursion : TC : O(2^N * N)
        // with memo : TC : O(N)

        
        
    }
};