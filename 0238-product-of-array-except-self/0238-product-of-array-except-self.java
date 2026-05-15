class Solution {
    public int[] productExceptSelf(int[] nums) {

        /*
         * APPROACH: Prefix + Suffix Product (Space Optimized)
         *
         * Naive approach: build two separate arrays for prefix and suffix products → O(n) space
         *
         * Key Insight: we don't need both arrays simultaneously.
         * - First pass: store prefix products directly in ans[]
         * - Second pass: maintain a running suffix product (single variable)
         *               and multiply into ans[] right to left
         *
         * This way ans[] does double duty — no extra arrays needed.
         *
         * TC: O(n) — two linear passes
         * SC: O(1) — ans[] is the required output, not counted as extra space
         *            only one extra variable (suffixp) used
         */

        int n = nums.length;
        int[] ans = new int[n];

        // Pass 1: fill ans[i] with product of all elements to the LEFT of i
        // ans[0] = 1 because nothing exists to the left of index 0
        // ans[i] = ans[i-1] * nums[i-1]  (extend left product by one element)
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Pass 2: multiply ans[i] by product of all elements to the RIGHT of i
        // suffixp tracks running product from right, starts at 1 (nothing to right of last element)
        // traverse right to left — suffixp grows as we move left
        int suffixp = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * suffixp; // ans[i] now = left product * right product
            suffixp *= nums[i];        // expand suffix product to include nums[i]
        }

        return ans;
    }
}