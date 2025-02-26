class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
         
         int n = nums.size();

         int currSubsum = nums[0];
         int maxSubsum = nums[0];

         for(int i=1; i<n; i++){
            currSubsum = max(nums[i], currSubsum + nums[i]);
            maxSubsum = max(currSubsum, maxSubsum);
         }

         int minSubsum = nums[0];
         currSubsum = nums[0];
         for(int i=1; i<n; i++){
            currSubsum = min(nums[i], currSubsum + nums[i]);
            minSubsum = min(currSubsum, minSubsum);
         }

         return max(abs(maxSubsum), abs(minSubsum));
        
    }
};