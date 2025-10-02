class Solution {
public:
    int rob(vector<int>& nums) {

        // bottom up - constant space
        int n = nums.size();
        vector<int> dp(n+1,0);

        int prev = nums[0];
        int prevprev = 0;

        for(int i=2; i<=n; i++){

            int skip = prev;
            int take = nums[i-1] + prevprev;

            dp[i] = max(skip, take);
            
            prevprev = prev;
            prev = dp[i];
            


        }


        return prev;
        
    }
};