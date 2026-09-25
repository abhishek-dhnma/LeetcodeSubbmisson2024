class Solution {
    public int minOperations(int[] nums, int x) {

        int arrayLength = nums.length;
        int totalArraySum = 0;

        // Calculate the total sum of the entire array.
        for (int index = 0; index < arrayLength; index++) {
            totalArraySum += nums[index];
        }

        // Edge Case 1: If the sum of all elements is less than x, it's impossible.
        if (totalArraySum < x)
            return -1;
            
        // Edge Case 2: If the sum perfectly equals x, we need to remove every element.
        if (totalArraySum == x)
            return arrayLength;

        // The exact sum our middle subarray needs to hit
        int targetSubarraySum = totalArraySum - x;
        
        int maxSubarrayLength = -1; // initialized to -1 to track if we ever find a valid window
        int currentSubarraySum = 0;
        
        int leftPointer = 0;  // Represents the start of our sliding window
        int rightPointer = 0; // Represents the end of our sliding window
        
        // Sliding Window to find the longest subarray that equals targetSubarraySum
        while (rightPointer < arrayLength) {
            // Expand the window by adding the rightmost element
            currentSubarraySum += nums[rightPointer];

            // If our window sum is too big, shrink it from the left
            while (leftPointer <= rightPointer && currentSubarraySum > targetSubarraySum) {
                currentSubarraySum -= nums[leftPointer];
                leftPointer++;
            }

            // If we found the exact target sum, update our maximum window length
            if (currentSubarraySum == targetSubarraySum) {
                int currentWindowLength = rightPointer - leftPointer + 1;
                maxSubarrayLength = Math.max(maxSubarrayLength, currentWindowLength);
            }

            // Move the right pointer forward to keep expanding
            rightPointer++;
        }

        // Calculate final answer: Total elements - Longest middle subarray = Minimum edge elements removed
        return (maxSubarrayLength == -1) ? -1 : (arrayLength - maxSubarrayLength);
    }
}