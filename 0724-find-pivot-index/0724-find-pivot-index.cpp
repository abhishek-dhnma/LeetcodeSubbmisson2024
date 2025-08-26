class Solution {
public:
    int pivotIndex(vector<int>& nums) {
int n = nums.size();

        int sum = 0;

        // Prefix Sum without extra memory

        for(int i =1; i<n; i++){
            nums[i] = nums[i-1] + nums[i];
        }

        // clever technique
        for(int i=0; i<n; i++){
            if(sum == nums[n-1] - nums[i]){
                return i;
                break;
            }
            sum = nums[i];

        }

        return -1;

    }
};