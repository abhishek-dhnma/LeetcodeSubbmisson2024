class Solution {

    /**
     * Standard Binary Search helper.
     * Searches for a target value within a specific range [i, j] of a sorted array.
     */
    static int binarysearch(int[] nums, int i, int j, int target){
        
        while(i <= j){
            // Prevention against integer overflow. Same as (i + j) / 2, 
            // but safe if i and j are very large numbers.
            int mid = i + (j-i)/2;

            if(nums[mid] == target){
                return mid; // Target found, return its index.
                
            } else if(nums[mid] > target){
                // Target is smaller, so it must be in the left half.
                j = mid - 1;
            } else {
                // Target is larger, so it must be in the right half.
                i = mid + 1;
            }
        }

        return -1; // Target does not exist in this range.
    }


    /**
     * Finds the index of the minimum element (the pivot point) in a rotated sorted array.
     * The minimum element is the original starting point of the sorted array before rotation.
     */
    static int findMinimumElement(int[] nums){
        int n = nums.length;
        int r = n - 1;
        int l = 0;

        // Using strictly less than (<) because we are narrowing down to a single element.
        // When l == r, that index is our minimum element.
        while(l < r){
            int mid = l + (r-l)/2;

            // If mid element is smaller than the rightmost element, the minimum element 
            // must be on the left side (including mid itself). 
            // Example: [4, 5, 1, 2, 3] -> mid is 1, right is 3. 1 < 3, so pivot is in [4, 5, 1]
            if(nums[mid] < nums[r]){
                r = mid; 
            } else {
                // If mid element is greater than or equal to the rightmost element, 
                // the array has rotated, and the minimum element is strictly to the right of mid.
                // Example: [3, 4, 5, 1, 2] -> mid is 5, right is 2. 5 > 2, so pivot is in [1, 2]
                l = mid + 1; 
            }
        }

        // l (or r) now points to the smallest element in the rotated array.
        return l;
    }


    /**
     * Main search function for a Rotated Sorted Array.
     * Strategy:
     * 1. Locate the pivot (minimum element).
     * 2. The pivot splits the array into two distinct, perfectly sorted subarrays:
     *    - Left subarray: From index 0 up to (minimumIndex - 1)
     *    - Right subarray: From index minimumIndex up to (n - 1)
     * 3. Run a standard binary search on both halves to find the target.
     */
    public int search(int[] nums, int target) {
        int n = nums.length;
        
        // Step 1: Find where the array rotation peak/valley is.
        int minimumIndex = findMinimumElement(nums);

        // Quick check: If the minimum element is our target, we are done.
        if(nums[minimumIndex] == target){
            return minimumIndex;
        }

        // Step 2: Search the left sorted subarray (values larger than the pivot segment).
        // Note: binarysearch handles cases where minimumIndex-1 is out of bounds (like -1) gracefully because i > j.
        int index = binarysearch(nums, 0, minimumIndex - 1, target);
        if(index != -1) return index; // Found it in the left half!

        // Step 3: Search the right sorted subarray (values from the pivot to the end).
        // We start from minimumIndex + 1 because we already checked minimumIndex above.
        index = binarysearch(nums, minimumIndex + 1, n - 1, target);

        return index; // Will return the index if found, or -1 if completely absent.
    }
}