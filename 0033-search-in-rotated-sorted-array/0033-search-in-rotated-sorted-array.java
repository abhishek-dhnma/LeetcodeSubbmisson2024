class Solution {
    public int search(int[] nums, int target) {

        int n = nums.length;
        int i = 0;
        int j = n - 1;

        while(i <= j){
            // Prevent potential integer overflow compared to (i + j) / 2
            int mid = i + (j - i) / 2;

            // Base Case: Target found immediately
            if(nums[mid] == target){
                 return mid;
            }
            
            // KEY CONCEPT: In a rotated sorted array, at least one half (left or right) 
            // from the 'mid' point will ALWAYS be perfectly sorted.
            
            else if(nums[i] <= nums[mid]){
                // --- CASE 1: The LEFT half is strictly sorted ---
                // Example: [4, 5, 6, 7, 0, 1, 2] -> mid is 7, i is 4. (4 <= 7) is true.

                // Check if the target realistically falls within this sorted left boundary
                if(nums[i] <= target && target < nums[mid]){
                    j = mid - 1; // Target is in the left sorted range, narrow search here
                } else {
                    i = mid + 1; // Target is outside this range, must be in the right half
                }

            } else if (nums[mid] <= nums[j]){
                // --- CASE 2: The RIGHT half is strictly sorted ---
                // Example: [6, 7, 0, 1, 2, 4, 5] -> mid is 1, j is 5. (1 <= 5) is true.

                // Check if the target realistically falls within this sorted right boundary
                if(nums[mid] < target && target <= nums[j]){
                    i = mid + 1; // Target is in the right sorted range, narrow search here
                } else {
                    j = mid - 1; // Target is outside this range, must be in the left half
                }
            }
        }

        // Target was never found after space exhaustion
        return -1; 
    }
}