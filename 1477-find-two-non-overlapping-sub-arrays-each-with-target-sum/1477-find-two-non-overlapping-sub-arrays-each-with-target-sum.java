class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        
        // Sliding window pointers and state
        int i = 0, j = 0, currSum = 0;
        
        // Scoreboard for the final answer
        int minSum = Integer.MAX_VALUE;
        
        // DP Array (The Signposts)
        int[] bestMinLengthSoFar = new int[n];
        Arrays.fill(bestMinLengthSoFar, Integer.MAX_VALUE);
        
        // Tracks the best single length we've seen at any point in time
        int currentBestLen = Integer.MAX_VALUE; 

        while (j < n) {
            // 1. Expand window
            currSum += arr[j];

            // 2. Shrink window (i <= j handles oversized elements!)
            while (i <= j && currSum > target) {
                currSum -= arr[i];
                i++;
            }

            // 3. Process valid match
            if (currSum == target) {
                int currLen = j - i + 1;
                
                // LOOK BACK: Find a non-overlapping partner from the signpost at i-1
                // Guard against i=0 (no past exists) and MAX_VALUE (overflow risk)
                if (i > 0 && bestMinLengthSoFar[i - 1] != Integer.MAX_VALUE) {
                    minSum = Math.min(minSum, currLen + bestMinLengthSoFar[i - 1]);
                }
                
                // Update our running best single length
                currentBestLen = Math.min(currentBestLen, currLen);
            }

            // 4. Plant the signpost for the current index EVERY loop
            // It carries forward the best length seen from 0 to j
            bestMinLengthSoFar[j] = currentBestLen;
            
            j++;
        }

        // If minSum is still Infinity, we didn't find TWO sub-arrays.
        return minSum == Integer.MAX_VALUE ? -1 : minSum;
    }
}