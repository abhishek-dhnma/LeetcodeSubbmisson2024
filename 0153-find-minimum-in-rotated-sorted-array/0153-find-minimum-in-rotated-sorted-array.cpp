class Solution {
public:

    int solve(vector<int> nums){

        int size = nums.size();
        int left = 0;
        int right = size-1;
        

        while(left<right){

            int mid = ((right-left)>>1)+left;

            if(nums[mid] > nums[right]){
                    left = mid+1;
            }else{
                    right = mid;
            }

        }

        return nums[right];

    }

    int findMin(vector<int>& nums) {
        
        return solve(nums);
        
        
    }
};