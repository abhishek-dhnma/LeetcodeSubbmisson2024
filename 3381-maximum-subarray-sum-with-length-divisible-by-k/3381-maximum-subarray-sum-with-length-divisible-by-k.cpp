class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        // -------------------------------
        // STEP 1: Build prefix sum array
        // prefixSum[i] = sum of nums[0..i]
        // Helps to get any subarray-sum in O(1)
        // -------------------------------
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        long long maxsum = LLONG_MIN;  // Stores global maximum subarray sum

        // -------------------------------------------------------------
        // STEP 2: Try all starting offsets modulo k
        // Example: if k = 3, check starting at indices 0, 1, and 2
        // Because subarrays we consider are of fixed size k, stepping by k
        // -------------------------------------------------------------
        for(int s = 0; s < k; s++){

            int i = s;               // Starting position within this modulo group
            long long currSum = 0;   // Current running sum (Kadane-like)

            // -------------------------------------------------------------
            // We pick blocks of size k: [i..i+k-1], then jump to next: [i+k..i+2k-1]
            // -------------------------------------------------------------
            while(i < n && (i + k - 1) < n){

                int j = i + k - 1;  // End index of current block (size k)

                // ---------------------------------------------------------
                // STEP 3: Compute sum of current block in O(1)
                // block = nums[i] ... nums[j]  (exactly k elements)
                // Using prefix sums:
                //
                // sum(i..j) = prefix[j] - prefix[i-1]  (if i > 0)
                // ---------------------------------------------------------
                long long subsum = prefixSum[j] - (i > 0 ? prefixSum[i-1] : 0);

                // ---------------------------------------------------------
                // STEP 4: Apply Kadane’s algorithm logic
                //
                // Either:
                //    - start a new sequence at this block (subsum)
                //    - OR extend previous sequence (currSum + subsum)
                // ---------------------------------------------------------
                currSum = max(subsum, currSum + subsum);

                // Update global maximum
                maxsum = max(maxsum, currSum);

                // Jump to next block that starts k steps ahead
                i += k;
            }
        }

        return maxsum;
    }
};
