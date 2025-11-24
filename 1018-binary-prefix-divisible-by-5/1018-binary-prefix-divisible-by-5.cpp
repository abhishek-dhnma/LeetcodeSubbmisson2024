class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        int n = nums.size();

        vector<bool> ans(n);

        int reminder = 0;

        for(int i=0; i<n; i++){

            reminder = (reminder * 2 + nums[i])%5;

            ans[i] = (reminder == 0);
        }


        return ans;
        
    }
};