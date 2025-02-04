class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0];

        int maxSum = nums[0];

        int runSum = nums[0];
        for(int i=1; i<n; i++){
            int curr = nums[i];

            if(nums[i] == nums[i-1]) {
                runSum = nums[i];
                continue;
            }
            
            if(nums[i] > nums[i-1]){
                runSum = runSum + curr;
            }else if(nums[i] < nums[i-1]){
                runSum =  curr;
            }

            
            maxSum = max(maxSum, runSum);
            cout << runSum << " " << maxSum << endl;

        }

        return maxSum;
        
    }
};