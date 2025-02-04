class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0];

        int maxSum = nums[0];
        int runSum = nums[0];
        
        for(int i=1; i<n; i++){
            runSum += nums[i];
            if(nums[i] < nums[i-1] || nums[i] == nums[i-1]){
                runSum = nums[i];
            }
            maxSum = max(maxSum, runSum);
        }

        return maxSum;
        
    }
};