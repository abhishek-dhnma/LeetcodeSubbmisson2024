class Solution {
    public long[] resultArray(int[] nums, int k) {
        // Use long[] to prevent integer overflow on massive arrays
        long[] olddp = new long[k];
        long[] ans = new long[k];

        // Let the loop handle everything from index 0 onward
        for (int i = 0; i < nums.length; i++) {
            
            long[] newdp = new long[k];
            
            // Do the modulo on the current number first to prevent huge numbers
            int currMod = nums[i] % k; 

            // 1. Extend the old arrays
            for (int j = 0; j < k; j++) {
                if (olddp[j] > 0) {
                    // j is the OLD remainder. 
                    // olddp[j] is the COUNT.
                    int newRem = (j * currMod) % k;
                    newdp[newRem] += olddp[j];
                }
            }

            // 2. Start fresh
            newdp[currMod] += 1;
            
            // 3. Ring the cash register (add this step's subarrays to total)
            for (int z = 0; z < k; z++) {
                ans[z] += newdp[z];
            }
            
            // 4. Pass the new clipboard to the next iteration
            olddp = newdp;
        }

        return ans;
    }
}