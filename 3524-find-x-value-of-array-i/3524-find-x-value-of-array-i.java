class Solution {
    public long[] resultArray(int[] nums, int k) {
        
        // This will hold our final answer: the total count of all valid subarrays for each remainder.
        // Index 0 holds count of remainder 0, Index 1 holds count of remainder 1, etc.
        long[] totalSubarraysByRemainder = new long[k];
        
        // This represents our "Old Clipboard". 
        // It tracks how many subarrays ended at the PREVIOUS number, grouped by their remainders.
        long[] prevRemainderCounts = new long[k];
        
        // Walk through every number in the array one by one
        for (int i = 0; i < nums.length; i++) {
            
            // This represents our "New Clipboard" for the CURRENT number.
            // We start fresh with all zeros for this specific step.
            long[] currRemainderCounts = new long[k];
            
            // We do the modulo math on the current number immediately to avoid integer overflow
            // if nums[i] is a massive number like 10^9.
            int currElementMod = nums[i] % k;
            
            // ==========================================
            // STEP 1: EXTEND OLD SUBARRAYS
            // ==========================================
            // We look at all K possible remainders from the previous step
            for (int prevRem = 0; prevRem < k; prevRem++) {
                
                // If there were actually subarrays that left this remainder...
                if (prevRemainderCounts[prevRem] > 0) {
                    
                    // Multiply the OLD remainder by the CURRENT number's remainder.
                    // This tells us the NEW remainder of these extended subarrays.
                    int newRem = (prevRem * currElementMod) % k;
                    
                    // Move the entire group (count) of those old subarrays into their new remainder bucket.
                    currRemainderCounts[newRem] += prevRemainderCounts[prevRem];
                }
            }
            
            // ==========================================
            // STEP 2: START A FRESH SUBARRAY
            // ==========================================
            // The current number standing all by itself forms a brand new subarray.
            currRemainderCounts[currElementMod] += 1;
            
            // ==========================================
            // STEP 3: Count them
            // ==========================================
            // Now that our "New Clipboard" is fully built, add all of its subarrays 
            // into our global running total. This ensures we count subarrays of every possible length.
            for (int rem = 0; rem < k; rem++) {
                totalSubarraysByRemainder[rem] += currRemainderCounts[rem];
            }
            
            // ==========================================
            // STEP 4: PREPARE FOR NEXT ITERATION
            // ==========================================
            // Throw away the old clipboard. 
            // The current step's clipboard becomes the "old" clipboard for the next number in the loop.
            prevRemainderCounts = currRemainderCounts;
        }
        
        return totalSubarraysByRemainder;
    }
}