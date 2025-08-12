class Solution {
public:
    int mod = 1e9 + 7;

    vector<vector<int>> dp;

    int solve(int n, int nums, int x, vector<vector<int>> & dp) {

        // base cases
        // if nums power x is greater then x then so need go further

        if (n == 0) {
            return 1;
        }

        if(n < 0){
            return 0;
        }
        int currPower = pow(nums, x);
        if (currPower > n) {
            return 0;
        }

        // n == 0  found one way here

        if(dp[n][nums] != -1){
            return dp[n][nums];
        }
        

        // recursion

        int take = solve(n -currPower , nums + 1, x, dp);
        int skip = solve(n, nums+1, x, dp);

        return dp[n][nums] = (take + skip)%mod;
    }

    int numberOfWays(int n, int x) {
        int nums = 1;

        dp.resize(301,vector<int>(301,-1));


        return solve(n, nums, x, dp);
    }
};