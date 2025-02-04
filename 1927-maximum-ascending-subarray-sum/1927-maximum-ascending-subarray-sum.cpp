class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int maxSum = nums[0];
        int runSum = nums[0];

        for(int i=1; i<nums.size(); i++){
            runSum = (nums[i] > nums[i-1]) ? runSum + nums[i] : nums[i];
            maxSum = max(maxSum, runSum);
        }

        return maxSum;
        
    }
};