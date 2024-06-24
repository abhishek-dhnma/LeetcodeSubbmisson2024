class Solution {
public:

    int modifiedBinarySearch(vector<int>nums, int left, int right, int target){

        int size = nums.size();

        while(left <= right){

            int mid = ((right-left) >> 1) + left;

            if (nums[mid] == target) {
                return mid;
            }
            else if(nums[left] <= nums[mid] ) { // left
                if(nums[left] <= target && target <= nums[mid]){
                    right = mid-1;
                    }else{
                    left = mid+1;
                    }
            } else if(nums[mid] <= nums[right]){ // right
                if(nums[mid] <= target && target <= nums[right]){
                    left = mid+1;
                    }else{
                    right = mid-1;
                    }
            }
        }

        return -1;
    }


    int search(vector<int>& nums, int target) {
        int s = nums.size();
        

       return modifiedBinarySearch(nums,0, s-1,target);
    }
};