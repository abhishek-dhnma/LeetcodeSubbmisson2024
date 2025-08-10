class Solution {
public:
    int rob(vector<int>& nums) {

        // BOTTOM UP APPROACH

        int n = nums.size();

        if(n ==1) return nums[0];

        vector<int> bu(n+1,0);

        bu[0] = 0;
        bu[1] = nums[0];

        for(int i=2; i<=n; i++){

            int steal = nums[i-1] + bu[i-2];
            int skip = bu[i-1];

            bu[i]  = max(steal, skip);

        }


        return bu[n];
        
        
    }
};