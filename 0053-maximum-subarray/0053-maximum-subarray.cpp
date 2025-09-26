class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // kadane's algo

        int currSum = nums[0];
        int MaxSoFar = nums[0];

        for(int i=1; i< nums.size(); i++){

            currSum = max(nums[i], currSum + nums[i]);

            MaxSoFar = max(currSum, MaxSoFar);


        }


        return MaxSoFar;
        
    }
};